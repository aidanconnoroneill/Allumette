#include "scheduler/adaptivescheduler.h"

#include <future>
#include <limits>
#include <thread>
#include <vector>
#include "data/dataset.h"
#include "data/table.h"
#include "operator/abstract_operator.h"
#include "operator/csv_table_load_op.h"
#include "operator/table_partiton_op.h"
#include "planner/pisi_planner.h"
#include "planner/sipi_planner.h"
#include "scheduler/semaphore.h"
using std::promise;
using std::thread;
using std::vector;
std::unique_ptr<AbstractDataset> AdaptiveScheduler::Schedule(
    int parallelism, std::shared_ptr<AbstractOperator> root) {
  vector<thread> thread_list;
  vector<promise<bool>> promises;
  vector<Worker*> worker_list;
  for (int i = 0; i < parallelism; i++) {
    Worker* w = new Worker(i);
    worker_list.push_back(w);
    promise<bool> p;
    promises.push_back(p);
  }
  auto planner = PISIPlanner(parallelism);
  Semaphore s(parallelism);
  auto plan = planner.GeneratePISIPlan(root);
  std::vector<std::unique_ptr<AbstractDataset>>&& results =
      std::vector<std::unique_ptr<AbstractDataset>>();

  std::recursive_mutex results_mutex;
  for (int i = 0; i < parallelism; i++) {
    Worker* w = worker_list[i];
    std::shared_ptr<AbstractOperator> op = plan->upstream_ops_[i];
    thread_list.push_back(std::thread(&Worker::execute, w, std::ref(s), op,
                                      std::ref(results),
                                      std::ref(results_mutex)));
  }
  int backoff = 1;
  bool allDone = true;
  for (int i = 0; i < parallelism; i++) {
    std::chrono::milliseconds span(backoff);
    auto status = promises[i].get_future().wait_for(span);
    if (status != std::future_status::ready) {
      backoff *= 2;
      i = -1;
    }
    if (backoff > 1024) {
      break;
    }
  }
  if (backoff <= 1024) {
    for (int i = 0; i < parallelism; i++) {
      thread_list[i].join();
    }
    auto cast_plan = std::make_shared<TableGatherOp>();

    cast_plan->GatherResult(results);

    return cast_plan->Execute();
  } else {
    for (int i = 0; i < parallelism; i++) {
      auto status = promises[i].get_future().wait_for(backoff);
      if (status == std::future_status::ready) {
        thread_list[i].join();
      } else {
        vector<thread> thread_list_n;
        vector<Worker*> worker_list_n;
        for (int i = 0; i < parallelism; i++) {
          Worker* w = new Worker(i);
          worker_list_n.push_back(w);
          promise<bool> p;
          promises.push_back(p);
        }
        auto planner = SIPIPlanner(parallelism);
        Semaphore s(parallelism);
        auto newRoot = planner.GenerateSIPIPlan(root);
        std::vector<std::unique_ptr<AbstractDataset>>&& results =
            std::vector<std::unique_ptr<AbstractDataset>>();

        std::recursive_mutex results_mutex;
        for (int i = 0; i < parallelism; i++) {
          Worker* w = worker_list[i];
          std::shared_ptr<AbstractOperator> op = plan->upstream_ops_[i];
          thread_list.push_back(
              std::thread(&Worker::execute_p, w, std::ref(s), op,
                          std::ref(results), std::ref(results_mutex)),
              std::ref(promises[i]));
        }
      }
    }
    auto cast_plan = std::make_shared<TableGatherOp>();

    cast_plan->GatherResult(results);

    return cast_plan->Execute();
  }
}
