#include "scheduler/scheduler.h"

#include <limits>
#include <thread>
#include <vector>
#include "data/dataset.h"
#include "data/table.h"
#include "operator/abstract_operator.h"
#include "operator/csv_table_load_op.h"
#include "operator/table_partiton_op.h"
#include "planner/pisi_planner.h"
#include "scheduler/semaphore.h"
using std::thread;
using std::vector;
std::unique_ptr<AbstractDataset> Scheduler::Schedule(
    int parallelism, std::shared_ptr<AbstractOperator> root) {
  vector<thread> thread_list;
  vector<Worker*> worker_list;
  for (int i = 0; i < parallelism; i++) {
    Worker* w = new Worker(i);
    worker_list.push_back(w);
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
  for (int i = 0; i < parallelism; i++) {
    thread_list[i].join();
  }
  // s.wait();
  auto cast_plan = std::make_shared<TableGatherOp>();
  std::cout << results.size() << std::endl;

  cast_plan->GatherResult(results);

  return cast_plan->Execute();
}
