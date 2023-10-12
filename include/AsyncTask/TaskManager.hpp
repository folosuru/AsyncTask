#pragma once
#ifndef TES_THREADING_HEADER_THREADING_THREADING_HPP_
#define TES_THREADING_HEADER_THREADING_THREADING_HPP_
#include "dll_declspec.hpp"
#include <memory>
#include "AsyncTaskBase.hpp"
namespace AsyncTask {

void ASYNC_TASK_DLL add_task(const std::shared_ptr<AsyncTaskBase>&);


void start_thread();
void stop_thread();
void run_finished_tasks();
}
#endif  // TES_THREADING_HEADER_THREADING_THREADING_HPP_
