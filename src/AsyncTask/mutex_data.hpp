#pragma once
#ifndef TES_THREADING_SRC_THREADING_MUTEX_DATA_HPP_
#define TES_THREADING_SRC_THREADING_MUTEX_DATA_HPP_
#include <memory>
#include <AsyncTask/AsyncTaskBase.hpp>
namespace AsyncTask::mutex {

void add_thread_task(const std::shared_ptr<AsyncTaskBase>& task);

std::shared_ptr<AsyncTaskBase> pop_thread_task();

bool thread_task_empty();

void add_complete_task(const std::shared_ptr<AsyncTaskBase>& task);

std::shared_ptr<AsyncTaskBase> pop_complete_task();

bool complete_task_empty();
}
#endif //TES_THREADING_SRC_THREADING_MUTEX_DATA_HPP_
