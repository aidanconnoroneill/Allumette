#pragma once
#include <memory>

#include "data/dataset.h"

enum OperatorType {
  CSV_TABLE_LOADER = 0,
  CSV_TABLE_STORER = 1,
  PARTITION = 2,
  PARTITION_ACCESS = 3,
  LOOP_JOIN = 4,
  GATHER = 5
};

class AbstractOperator {
 public:
  AbstractOperator(OperatorType op_type) : op_type_(op_type) {}
  virtual ~AbstractOperator() = default;
  // We use smart pointer to manage the operators, thus we don't need to take
  // care about destructor.
  void AddFromOperator(std::shared_ptr<AbstractOperator> op) {
    upstream_ops_.push_back(op);
  }
  // We pass the dataset by smart pointer, it could address memory leak issues
  // significantly!
  virtual std::unique_ptr<AbstractDataset> Execute() = 0;
  // Decide whether the state of operator is valid,
  // for example, an join operator should only have two upstreams.
  virtual bool Validate() = 0;

  OperatorType GetOperatorType() { return op_type_; }

  virtual std::string ToString() {
    switch (op_type_) {
      case CSV_TABLE_LOADER:
        return "CSV_TABLE_LOADER";
        break;
      case CSV_TABLE_STORER:
        return "CSV_TABLE_STORER";
        break;
      case PARTITION:
        return "PARTITION";
        break;
      case PARTITION_ACCESS:
        return "PARTITION_ACCESS";
        break;
      case LOOP_JOIN:
        return "LOOP_JOIN";
        break;
      case GATHER:
        return "GATHER";
        break;
    }
    return "OP";
  }

 protected:
  // The node id will be set when generating physical DAG.
  std::vector<std::shared_ptr<AbstractOperator>> upstream_ops_;

  OperatorType op_type_;

  friend class PISIPlanner;
  friend class SIPIPlanner;
  friend class Scheduler;
  friend class AdaptiveScheduler;
};