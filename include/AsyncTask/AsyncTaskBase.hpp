#pragma once
#ifndef TES_THREADING_HEADER_THREADING_TASKBASE_HPP_
#define TES_THREADING_HEADER_THREADING_TASKBASE_HPP_
#include "dll_declspec.hpp"
namespace AsyncTask {
class ASYNC_TASK_DLL AsyncTaskBase {
public:
    virtual void onRun() = 0;

    virtual void onComplete() = 0;
};
}
#endif  // TES_THREADING_HEADER_THREADING_TASKBASE_HPP_
