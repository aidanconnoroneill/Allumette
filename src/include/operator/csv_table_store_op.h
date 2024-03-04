#pragma once
#include <cassert>
#include <utility>

#include "abstract_operator.h"
#include "data/csv.h"
#include "data/table.h"

class CSVTableStoreOperator : public AbstractOperator {
 public:
  CSVTableStoreOperator(std::string path)
      : AbstractOperator(OperatorType::CSV_TABLE_STORER),
        path_(std::move(path)) {}
  ~CSVTableStoreOperator() override {}
  std::unique_ptr<AbstractDataset> Execute() override;
  std::unique_ptr<AbstractDataset> Execute(std::unique_ptr<AbstractDataset>);
  bool Validate() override;

 private:
  std::string path_;
};