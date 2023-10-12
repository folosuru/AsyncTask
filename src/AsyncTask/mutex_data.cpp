#include "mutex_data.hpp"
#include <queue>
#include <mutex>
namespace AsyncTask {
class AsyncTaskBase;
namespace mutex {
std::mutex thread_task_lock;
std::queue<std::shared_ptr<AsyncTaskBase>> thread_task_queue;
std::mutex complete_task_lock;
std::queue<std::shared_ptr<AsyncTaskBase>> complete_task_queue;

void add_thread_task(const std::shared_ptr<AsyncTaskBase>& task) {
    std::lock_guard<std::mutex> lock_(thread_task_lock);
    thread_task_queue.push(task);
}

std::shared_ptr<AsyncTaskBase> pop_thread_task() {
    std::lock_guard<std::mutex> lock_(thread_task_lock);
    std::shared_ptr<AsyncTaskBase> result = thread_task_queue.front();
    thread_task_queue.pop();
    return result;
}

void add_complete_task(const std::shared_ptr<AsyncTaskBase>& task) {
    std::lock_guard<std::mutex> lock_(complete_task_lock);
    complete_task_queue.push(task);
}

std::shared_ptr<AsyncTaskBase> pop_complete_task() {
    std::lock_guard<std::mutex> lock_(complete_task_lock);
    std::shared_ptr<AsyncTaskBase> result = complete_task_queue.front();
    complete_task_queue.pop();
    return result;
}

bool thread_task_empty() {
    std::lock_guard<std::mutex> lock_(thread_task_lock);
    if (thread_task_queue.empty()) {
        return true;
    }
    return false;
}

bool complete_task_empty() {
    std::lock_guard<std::mutex> lock_(complete_task_lock);
    if (complete_task_queue.empty()) {
        return true;
    }
    return false;
}
}

}