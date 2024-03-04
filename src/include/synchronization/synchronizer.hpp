#ifndef SYNCHRONIZER_HPP
#define SYNCHRONIZER_HPP

#include <atomic>
#include <condition_variable>
#include <mutex>

using std::atomic;
using std::condition_variable;
using std::defer_lock;
using std::mutex;
using std::unique_lock;

using std::get;
using std::make_tuple;
using std::tuple;
namespace dsys {

class synchronizer {
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
  Synchronizer(int total_operations = 0) {
    total_operations_reset = total_operations;

    reset(total_operations);
  };

  Synchronizer(const Synchronizer& other)
      : Synchronizer(other.number_operations_left) {}

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
    if (number_operations_left == 0) {
      return;
    }
    if (thread_rank >= 0) {
      while (number_operations_left > 0) {
        if (dsys::release) {
          break;
        }
        if (!dsys::work[dsys::thread_rank]->empty()) {
          tuple<void*, int> wrapped_func =
              dsys::work[dsys::thread_rank]->pop_remove();
          void* func = get<0>(wrapped_func);

          int message_size = get<1>(wrapped_func);
          uint64_t* message_header = reinterpret_cast<uint64_t*>(func);
          auto deserialize_call_function =
              reinterpret_cast<void (*)(void*, uint64_t)>(message_header[0]);
          deserialize_call_function(func, message_size);
        } else {
          usleep(10);
        }
      }
      //     unique_lock<mutex>
      //     ul_lock_work_has_completed(lock_work_has_completed);
      //     work_has_completed.wait(ul_lock_work_has_completed);
    } else {
      assert(false);
      unique_lock<mutex> ul_lock_work_has_completed(lock_work_has_completed);
      while (number_operations_left > 0) {
        work_has_completed.wait(ul_lock_work_has_completed);
      }
    }
  }

  void operator=(const Synchronizer& other) {
    reset(other.number_operations_left);
  }
};

};  // namespace dsys

#endif /* SYNCHRONIZER_HPP */