#pragma once
#ifndef TES_THREADING_HEADER_THREADING_TASKBASE_HPP_
#define TES_THREADING_HEADER_THREADING_TASKBASE_HPP_
#include "dll_declspec.hpp"
namespace AsyncTask {
/**
 * AsyncTaskBase
 *
 * to use AsyncTask, extend this class...
 */
class ASYNC_TASK_DLL AsyncTaskBase {
public:
    /**
     * onRun
     * running in other thread.
     */
    virtual void onRun() = 0;

    /**
     * onComplete
     * running in main thread.
     */
    virtual void onComplete() = 0;
};
}
#endif  // TES_THREADING_HEADER_THREADING_TASKBASE_HPP_
