
#include <iostream>

#include "operator/table_partiton_op.h"
std::unique_ptr<AbstractDataset> HashTablePartitionOperator::Execute() {
  std::lock_guard guard(mu_);
  if (is_executed_) {
    return nullptr;
  }

  std::unordered_map<size_t, std::vector<Row>> hash_map_;
  auto data = upstream_ops_[0]->Execute();
  assert(data->Type() == DatasetType::TABLE);
  auto table = reinterpret_cast<Table*>(data.get());
  for (size_t i = 0; i < table->Size(); ++i) {
    Row& row = table->GetRowByIndex(i);
    size_t hash_val =
        row.GetColumnByIdx(column_id_).HashValue() % num_of_partitions_;
    if (auto iter = hash_map_.find(hash_val); iter == hash_map_.end()) {
      hash_map_[hash_val] = std::vector<Row>();
    }
    hash_map_[hash_val].push_back(row);
  }

  for (auto& [k, v] : hash_map_) {
    auto part = std::make_unique<Table>(table->GetSchema(), std::move(v),
                                        table->GetTableName());
    partitions_[k] = std::move(part);
  }
  is_executed_ = true;
  return nullptr;
}

std::unique_ptr<AbstractDataset> HashTablePartitionOperator::GetDataSetByIndex(
    size_t idx) {
  return std::move(partitions_[idx]);
}

bool HashTablePartitionOperator::Validate() {
  return upstream_ops_.size() == 1 && upstream_ops_[0]->Validate();
}

std::unique_ptr<AbstractDataset> PartitionAccessOperator::Execute() {
  upstream_ops_[0]->Execute();
  auto up_op =
      reinterpret_cast<HashTablePartitionOperator*>(upstream_ops_[0].get());
  return up_op->GetDataSetByIndex(index_);
}

bool PartitionAccessOperator::Validate() {
  return upstream_ops_.size() == 1 &&
         upstream_ops_[0]->GetOperatorType() == OperatorType::PARTITION &&
         upstream_ops_[0]->Validate();
}
