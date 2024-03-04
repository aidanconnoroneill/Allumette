#include "planner/sipi_planner.h"

#include "operator/gather_op.h"
#include "operator/join_op.h"
#include "operator/table_partiton_op.h"
std::vector<std::shared_ptr<AbstractOperator>> SIPIPlanner::GenerateSIPIPlan(
    std::shared_ptr<AbstractOperator> root) {
  std::vector<std::shared_ptr<AbstractOperator>> ret;
  std::shared_ptr<AbstractOperator> new_root = nullptr;
  switch (root->GetOperatorType()) {
    case LOOP_JOIN: {
      auto op_ptr = reinterpret_cast<LoopJoinOp*>(root.get());
      auto left_op = GenerateSIPIPlan(op_ptr->upstream_ops_[0])[0];
      auto right_op = GenerateSIPIPlan(op_ptr->upstream_ops_[1])[0];
      // Add data partition operator for left and right table
      auto left_data_part_op = std::make_shared<HashTablePartitionOperator>(
          op_ptr->left_index_, parallelism_);
      auto right_data_part_op = std::make_shared<HashTablePartitionOperator>(
          op_ptr->right_index_, parallelism_);

      left_data_part_op->AddFromOperator(left_op);
      right_data_part_op->AddFromOperator(right_op);

      std::vector<std::shared_ptr<AbstractOperator>> left_access_ops;
      for (size_t i = 0; i < parallelism_; ++i) {
        auto ptr = std::make_shared<PartitionAccessOperator>(i);
        ptr->AddFromOperator(left_data_part_op);
        left_access_ops.push_back(ptr);
      }
      std::vector<std::shared_ptr<AbstractOperator>> right_access_ops;
      for (size_t i = 0; i < parallelism_; ++i) {
        auto ptr = std::make_shared<PartitionAccessOperator>(i);
        ptr->AddFromOperator(right_data_part_op);
        right_access_ops.push_back(ptr);
      }

      std::vector<std::shared_ptr<AbstractOperator>> join_ops;
      for (size_t i = 0; i < parallelism_; ++i) {
        auto ptr = std::make_shared<LoopJoinOp>(op_ptr->left_index_,
                                                op_ptr->right_index_);
        ptr->AddFromOperator(left_access_ops[i]);
        ptr->AddFromOperator(right_access_ops[i]);
        join_ops.push_back(ptr);
      }

      auto gather_op = std::make_shared<TableGatherOp>();
      auto gather_op_2 = std::make_shared<TableGatherOp>();
      for (const auto& op : join_ops) {
        gather_op->AddFromOperator(op);
        gather_op_2->AddFromOperator(op);
      }
      ret.push_back(gather_op);
      ret.push_back(gather_op_2);
    } break;
    default: {
      ret.push_back(root);
      return ret;
    }
  }
  return ret;
}