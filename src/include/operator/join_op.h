#pragma once
#include "abstract_operator.h"

class LoopJoinOp : public AbstractOperator {
 public:
  LoopJoinOp(size_t left_index, size_t right_index)
      : AbstractOperator(OperatorType::LOOP_JOIN),
        left_index_(left_index),
        right_index_(right_index) {}
  std::unique_ptr<AbstractDataset> Execute() override;
  bool Validate() override;
  virtual std::string ToString() {
    return "JOIN left index: " + std::to_string(left_index_) +
           " right index: " + std::to_string(right_index_);
  }

 private:
  size_t left_index_;
  size_t right_index_;
  friend class PISIPlanner;
  friend class SIPIPlanner;
};
