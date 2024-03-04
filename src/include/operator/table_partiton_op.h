#pragma once
#include <mutex>
#include <thread>
#include <vector>

#include "abstract_operator.h"
#include "data/table.h"
// Table Partition Operator will divide table into shards based on column.
// Table Partition Operator do not return data when Execution is called.
// We need to add  ReadTablePartitionrOperators after that to fetch the
// partition we need. There might be multiple readers wants to call the execute
// method. But we will enure the operator is only executed for once.

class HashTablePartitionOperator : public AbstractOperator {
 public:
  HashTablePartitionOperator(size_t column_id, size_t num_of_partitions)
      : AbstractOperator(PARTITION),
        column_id_(column_id),
        num_of_partitions_(num_of_partitions),
        is_executed_(false) {}

  ~HashTablePartitionOperator() override = default;

  std::unique_ptr<AbstractDataset> Execute() override;

  bool Validate() override;

  std::unique_ptr<AbstractDataset> GetDataSetByIndex(size_t idx);

 private:
  bool is_executed_;
  size_t column_id_;
  size_t num_of_partitions_;
  std::mutex mu_;
  std::unordered_map<size_t, std::unique_ptr<AbstractDataset>> partitions_;
};

class PartitionAccessOperator : public AbstractOperator {
 public:
  PartitionAccessOperator(size_t index)
      : AbstractOperator(OperatorType::PARTITION_ACCESS), index_(index) {}

  std::unique_ptr<AbstractDataset> Execute() override;

  bool Validate() override;
  virtual std::string ToString() {
    return "Parittion access: " + std::to_string(index_);
  }

 private:
  size_t index_;
};