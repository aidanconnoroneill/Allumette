#pragma once
#include <memory>
#include <vector>

#include "dataset.h"
#include "table.h"
#include "value.h"
// Schema defines the data_type and name of column
struct ColumnInfo {
  ValueType type_;
  std::string name_;
  ColumnInfo(ValueType type, std::string name)
      : type_(type), name_(std::move(name)) {}
  ColumnInfo(const ColumnInfo& info) {
    type_ = info.type_;
    name_ = info.name_;
  }
  ColumnInfo(ColumnInfo&& info) {
    type_ = info.type_;
    name_ = std::move(info.name_);
  }

  ColumnInfo& operator=(const ColumnInfo& column_info) {
    type_ = column_info.type_;
    name_ = column_info.name_;
    return *this;
  }
};
struct Schema {
 public:
  Schema(std::vector<ColumnInfo>&& columns) : columns_(columns) {}
  Schema(Schema& schema) {
    for (const auto& col : schema.columns_) {
      columns_.push_back(col);
    }
  }
  Schema(Schema&& schema) {
    for (auto col : schema.columns_) {
      columns_.push_back(std::move(col));
    }
  }

  std::vector<ColumnInfo> columns_;
};

class Table : public AbstractDataset {
 public:
  Table(Schema&& schema, std::vector<Row>&& vals, std::string&& name = "")
      : AbstractDataset(std::move(name), DatasetType::TABLE),
        name_(name),
        schema_(std::move(schema)),
        vals_(std::move(vals)) {}

  Row& GetRowByIndex(size_t idx) {
    assert(idx >= 0 && idx < vals_.size());
    return vals_[idx];
  }

  size_t Size() { return vals_.size(); }
  Schema GetSchema() { return schema_; }

  std::string GetTableName() { return name_; }

  static std::unique_ptr<AbstractDataset> MergeTables(
      std::vector<std::unique_ptr<AbstractDataset>>&& tables) {
    auto table_0 = reinterpret_cast<Table*>(tables[0].get());
    auto new_table = std::make_unique<Table>(std::move(table_0->GetSchema()),
                                             std::move(table_0->vals_));
    for (size_t i = 1; i < tables.size(); ++i) {
      auto table = reinterpret_cast<Table*>(tables[1].get());
      new_table->vals_.insert(new_table->vals_.end(), table->vals_.begin(),
                              table->vals_.end());
    }
    return new_table;
  }

 private:
  std::string name_;
  DatasetType type_;
  std::vector<Row> vals_;
  Schema schema_;
};
