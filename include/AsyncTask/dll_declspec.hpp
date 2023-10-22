#pragma once
#ifndef TES_THREADING_HEADER_THREADINGTASK_DLL_DECLSPEC_HPP_
#define TES_THREADING_HEADER_THREADINGTASK_DLL_DECLSPEC_HPP_
#ifdef AsyncTask_NOT_USE_DLL
#define ASYNC_TASK_DLL
#else

#ifdef AsyncTask_EXPORTS
#define ASYNC_TASK_DLL __declspec(dllexport)
#else
#define ASYNC_TASK_DLL __declspec(dllimport)
#endif

#endif
#endif //TES_THREADING_HEADER_THREADINGTASK_DLL_DECLSPEC_HPP_
