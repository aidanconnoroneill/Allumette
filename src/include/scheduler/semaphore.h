#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <atomic>
#include <condition_variable>
#include <mutex>

using std::atomic;
using std::condition_variable;
using std::defer_lock;
using std::mutex;
using std::unique_lock;

class Semaphore {
 private:
  int total_operations_reset;

  // Condition variable that is used to signal when work is completed (i.e.
  // number_operations_left is 0)
  condition_variable work_has_completed;

  // A mutex that guards number_operations_left
  mutex lock_work_has_completed;

 public:
  // Number of operations left to complete in the task.  Initialized to the
  // total number of operations
  atomic<int> number_operations_left;
  // Constructor
  Semaphore(int total_operations = 0) {
    total_operations_reset = total_operations;

    reset(total_operations);
  };

  Semaphore(const Semaphore& other) : Semaphore(other.number_operations_left) {}

  inline void increase() { number_operations_left++; }

  inline void increase(int ops) { number_operations_left += ops; }

  // An operation has completed -- decrease the number of operations left, then
  // signal if there is no work left
  inline void decrease() {
    if (number_operations_left.fetch_sub(1, std::memory_order_acquire) == 1) {
      unique_lock<mutex> ul_notification_mutex(lock_work_has_completed);

      work_has_completed.notify_all();

      ul_notification_mutex.unlock();
    }
  }

  inline void reset(int total_operations = 0) {
    number_operations_left.store(total_operations, std::memory_order_release);
  }

  inline void wait() {
    unique_lock<mutex> ul_lock_work_has_completed(lock_work_has_completed);

    if (number_operations_left == 0) {
      return;
    }

    work_has_completed.wait(ul_lock_work_has_completed);
  }

  void operator=(const Semaphore& other) {
    reset(other.number_operations_left);
  }
};
#endif /* SEMAPHORE_HPP */
