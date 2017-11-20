#include "taskobserver.h"

TaskObserver &TaskObserver::getInstance()
{
    static TaskObserver instance;
    return instance;
}

TaskObserver::TaskObserver() {}

void TaskObserver::startTask(int id, TaskPerformerInterface* task)
{
    mtx.lock();
        printTime();
        cout << "Task started on thread: " << id << ": " << task->getDescription() << endl << endl;
    mtx.unlock();
}

void TaskObserver::endTask(int id, TaskPerformerInterface* task, chrono::duration<long long int, nano> elapsed)
{
    mtx.lock();
        printTime();
        cout << "Task ended on thread: " << id << ": " << task->getDescription() << endl;
        cout << "Execution time: " << elapsed.count() << " nanoseconds" << endl << endl;
    mtx.unlock();
}

void TaskObserver::printTime()
{
    chrono::system_clock::time_point p = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(p);
    cout << ctime(&t);
}
