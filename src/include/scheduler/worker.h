#pragma once
#include <future>
#include <memory>
#include <thread>
#include "operator/abstract_operator.h"
#include "operator/table_partiton_op.h"
#include "scheduler/semaphore.h"
using std::promise;
class Worker {
 public:
  Worker(int id) : id(id) {}
  virtual ~Worker() = default;
  // We use smart pointer to manage the operators, thus we don't need to take
  // care about destructor.
  void execute(Semaphore& s, std::shared_ptr<AbstractOperator> op,
               std::vector<std::unique_ptr<AbstractDataset>>& results,
               std::recursive_mutex& results_mutex) {
    auto result = op->Execute();
    // results_mutex.lock();
    results.push_back(std::move(result));
    // results_mutex.unlock();
    // s.decrease();
  }
  void execute_p(Semaphore& s, std::shared_ptr<AbstractOperator> op,
                 std::vector<std::unique_ptr<AbstractDataset>>& results,
                 std::recursive_mutex& results_mutex, promise<bool> p) {
    auto result = op->Execute();
    // results_mutex.lock();
    results.push_back(std::move(result));
    p.set_value(true);
    // results_mutex.unlock();
    // s.decrease();
  }

 protected:
  int id;
};
//