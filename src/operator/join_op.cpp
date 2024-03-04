#include "operator/join_op.h"

#include <iostream>
#include <memory>
#include "data/table.h"

bool LoopJoinOp::Validate() {
  return upstream_ops_.size() == 2 && upstream_ops_[0]->Validate() &&
         upstream_ops_[1]->Validate();
}

std::unique_ptr<AbstractDataset> LoopJoinOp::Execute() {
  auto left_data = upstream_ops_[0]->Execute();
  auto right_data = upstream_ops_[1]->Execute();
  auto left_table = reinterpret_cast<Table*>(left_data.get());
  auto right_table = reinterpret_cast<Table*>(right_data.get());
  std::vector<Row> result;
  for (size_t i = 0; i < left_table->Size(); ++i) {
    auto& left_row = left_table->GetRowByIndex(i);
    for (size_t j = 0; j < right_table->Size(); ++j) {
      auto& right_row = right_table->GetRowByIndex(j);
      auto& left_val = left_row.GetColumnByIdx(left_index_);
      auto& right_val = right_row.GetColumnByIdx(right_index_);
      if (left_val == right_val) {
        Row new_row = Row(left_row);
        new_row.AppendRow(right_row);
        result.push_back(std::move(new_row));
      }
    }
  }
  Schema new_schema = left_table->GetSchema();
  Schema right_schema = right_table->GetSchema();
  new_schema.columns_.insert(new_schema.columns_.end(),
                             right_schema.columns_.begin(),
                             right_schema.columns_.end());
  auto table =
      std::make_unique<Table>(std::move(new_schema), std::move(result));
  return table;
}