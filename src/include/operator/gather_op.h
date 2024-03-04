#pragma once
#include <utility>

#include "abstract_operator.h"
// TableGatherOp operator is used to union results from multiple operators in
// PISI plan or SIPI plan For example: A.part1 join B.part1 union B.part2 join
// B.part2

// In the single thread, TableGatherOp will execute the children operators
// sequentially.

// For parallel execution scheduler, the Execute method should not be called.
// It is just a "symbol" executor (you can think it as a barrier) tells the
// scheduler the children of gather op can work in parallel. The scheduler
// should get all children of GatherOp and let them run in multiple threads.
// (Try to use friend class) Then scheduler collects results and call
// "GatherResult" manually. So the father node of TableGather node can call the
// Execute() as normal to get result.
class TableGatherOp : public AbstractOperator {
 public:
  TableGatherOp() : AbstractOperator(GATHER) {}
  std::unique_ptr<AbstractDataset> Execute() override;
  void GatherResult(std::vector<std::unique_ptr<AbstractDataset>>& results) {
    results_ = std::move(results);
  }

  bool Validate() override;

 private:
  std::vector<std::unique_ptr<AbstractDataset>> results_;
};