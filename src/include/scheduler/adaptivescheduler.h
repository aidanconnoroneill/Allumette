#pragma once
#include <memory>
#include "data/dataset.h"
#include "scheduler/worker.h"
class AdaptiveScheduler {
 public:
  AdaptiveScheduler() = default;
  virtual ~AdaptiveScheduler() = default;

  std::unique_ptr<AbstractDataset> Schedule(
      int num_threads, std::shared_ptr<AbstractOperator> root);
};
