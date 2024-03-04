#pragma once
#include <utility>
#include "abstract_operator.h"
#include "data/csv.h"
#include "data/table.h"

class CSVTableLoadOperator : public AbstractOperator {
 public:
  CSVTableLoadOperator(std::string path, Schema&& schema)
      : path_(std::move(path)),
        schema_(std::move(schema)),
        AbstractOperator(CSV_TABLE_LOADER) {}
  ~CSVTableLoadOperator() override {}
  std::unique_ptr<AbstractDataset> Execute() override;
  bool Validate() override;

 private:
  std::string path_;
  Schema schema_;
};
