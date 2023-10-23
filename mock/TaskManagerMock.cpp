#include <AsyncTask/TaskManager.hpp>
#include <AsyncTask/AsyncTaskBase.hpp>
#include <memory>

/**
 * How to use mock;
 * 1. define AsyncTask_NOT_USE_DLL macro.
 * 2. add this file to build target.
 */

namespace AsyncTask {
void add_task(const std::shared_ptr<AsyncTaskBase>& task) {
    task->onRun();
    task->onComplete();
}
}