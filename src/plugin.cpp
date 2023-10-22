/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

#include <llapi/LoggerAPI.h>
#include <llapi/ScheduleAPI.h>
#include <llapi/EventAPI.h>
#include <AsyncTask/TaskManager.hpp>
#include "AsyncTask/AsyncTask_manager.hpp"
#include "version.h"

// We recommend using the global logger.
extern Logger logger;

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *        
 */
void PluginInit() {
    AsyncTask::start_thread();

    Event::ServerStoppedEvent::subscribe([](const Event::ServerStoppedEvent& event) {
        AsyncTask::stop_thread();
        return true;
    });

    Schedule::repeat([](){
        AsyncTask::run_finished_tasks();
    },2);
}
