#include "operator/gather_op.h"

#include "data/table.h"
std::unique_ptr<AbstractDataset> TableGatherOp::Execute() {
  // Single thread mode
  if (results_.size() == 0) {
    for (auto& op : upstream_ops_) {
      results_.push_back(op->Execute());
    }
  }
  // Multiple threads mode
  // Scheduler should call GatherData before
  // Just merge the table directly.
  return Table::MergeTables(std::move(results_));
}

bool TableGatherOp::Validate() {
  for (auto& op : upstream_ops_) {
    if (!op->Validate()) {
      return false;
    }
  }
  return true;
}