#pragma once
#include <cassert>
#include <cstddef>
#include <iostream>
#include <set>
#include <stack>
#include "operator/abstract_operator.h"
#include "operator/gather_op.h"
class SIPIPlanner {
 public:
  // User needs to specify the parallelism degree for execution plan.
  // For example, if parallelism == 2, we need to 2 join operators and partition
  // tables into 2 parts.
  SIPIPlanner(size_t parallelism) {
    assert(parallelism > 0);
    parallelism_ = parallelism;
  }

  std::vector<std::shared_ptr<AbstractOperator>> GenerateSIPIPlan(
      std::shared_ptr<AbstractOperator> root);

  static void PrintPlan(std::shared_ptr<AbstractOperator> root) {
    std::stack<AbstractOperator*> q;
    std::stack<AbstractOperator*> next_layer;
    std::set<AbstractOperator*> ops_;
    next_layer.push(root.get());
    while (!next_layer.empty()) {
      q = next_layer;
      next_layer = std::stack<AbstractOperator*>();
      while (!q.empty()) {
        auto ptr = q.top();
        q.pop();
        std::cout << ptr->ToString() << "  ";
        for (auto& op : ptr->upstream_ops_) {
          if (auto iter = ops_.find(op.get()); iter == ops_.end()) {
            ops_.insert(op.get());
            next_layer.push(op.get());
          }
        }
      }
      std::cout << std::endl;
    }
  }

 private:
  size_t parallelism_;
};
