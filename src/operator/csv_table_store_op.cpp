#include "operator/csv_table_store_op.h"

#include <ostream>
std::unique_ptr<AbstractDataset> CSVTableStoreOperator::Execute() {
  auto data = upstream_ops_[0]->Execute();
  assert(data->Type() == DatasetType::TABLE);
  Execute(std::move(data));
  return nullptr;
}
std::unique_ptr<AbstractDataset> CSVTableStoreOperator::Execute(
    std::unique_ptr<AbstractDataset> data) {
  std::filebuf fb;
  fb.open(path_, std::ios::out);
  std::ostream os(&fb);

  auto writer = csv::make_csv_writer(os);
  auto table = reinterpret_cast<Table*>(data.get());
  Schema schema = table->GetSchema();
  std::vector<std::string> columns;
  for (auto& column : schema.columns_) {
    columns.push_back(column.name_);
  }
  writer << columns;
  for (size_t i = 0; i < table->Size(); ++i) {
    std::vector<std::string> csv_row;
    Row& row = table->GetRowByIndex(i);
    csv_row.reserve(schema.columns_.size());
    for (size_t j = 0; j < schema.columns_.size(); ++j) {
      csv_row.push_back(row.GetColumnByIdx(j).ToString());
    }
    writer << csv_row;
  }

  return nullptr;
}

bool CSVTableStoreOperator::Validate() {
  return upstream_ops_.size() == 1 && upstream_ops_[0]->Validate();
}