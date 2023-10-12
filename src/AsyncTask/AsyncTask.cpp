#include <AsyncTask/TaskManager.hpp>
#include <memory>
#include <thread>
#include <condition_variable>
#include "mutex_data.hpp"

#include <iostream>
namespace AsyncTask {
std::thread runnning_thread;

bool is_wakeup;
bool close_thread = false;
std::mutex cv_mtx;
std::condition_variable cv;

void add_task(const std::shared_ptr<AsyncTaskBase>& task) {
    mutex::add_thread_task(task);
    {
        std::lock_guard<std::mutex> lock(cv_mtx);
        is_wakeup = true;
        cv.notify_all();
    }
}

void start_thread() {
    runnning_thread = std::thread([](){
        while (true) {
            while (true) {
                if (mutex::thread_task_empty()) break;
                std::shared_ptr<AsyncTaskBase> task = mutex::pop_thread_task();
                task->onRun();
                mutex::add_complete_task(task);
            }

            {  // まつ
                std::unique_lock<std::mutex> lock_(cv_mtx);
                cv.wait(lock_, [&]() { return is_wakeup; });
                if (close_thread) return;  // おわり
            }
        }
    });

}

void run_finished_tasks() {
    while (true) {
        if (mutex::complete_task_empty()) break;
        std::shared_ptr<AsyncTaskBase> task = mutex::pop_complete_task();
        task->onComplete();
    }
}

void stop_thread() {
    {
        std::lock_guard<std::mutex> lock(cv_mtx);
        is_wakeup = true;
        close_thread = true;
        cv.notify_all();
    }
    runnning_thread.join();
}

}