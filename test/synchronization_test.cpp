#include "data/dataset.h"
#include "gtest/gtest.h"
#include "operator/csv_table_load_op.h"
#include "operator/csv_table_store_op.h"
#include "operator/join_op.h"
#include "planner/pisi_planner.h"
#include "scheduler/semaphore.h"
using std::thread;
using std::vector;
TEST(Semaphore, Synchronization) {
  Semaphore s(4);
  Semaphore o = s;
  ASSERT_EQ(4, o.number_operations_left);
  auto&& sleep_and_signal = [&]() {
    useconds_t sleepTime;
    sleepTime = (useconds_t)(((rand() % 5) + 1) * 10000);
    usleep(sleepTime);
    o.decrease();
  };
  vector<thread> thread_list;
  for (int i = 0; i < 4; i++) {
    thread_list.push_back(std::thread(sleep_and_signal));
  }
  o.wait();
  ASSERT_EQ(0, o.number_operations_left);
  for (int i = 0; i < 4; i++) {
    thread_list[i].join();
  }
  for (int i = 0; i < 4; i++) {
    thread_list.pop_back();
  }
  o.reset(8);
  ASSERT_EQ(8, o.number_operations_left);
  auto&& signal = [&]() { o.decrease(); };
  for (int i = 0; i < 8; i++) {
    thread_list.push_back(std::thread(signal));
  }
  o.wait();
  ASSERT_EQ(0, o.number_operations_left);
  for (int i = 0; i < 8; i++) {
    thread_list[i].join();
  }
}
