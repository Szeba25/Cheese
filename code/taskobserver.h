#ifndef TASKOBSERVER_H
#define TASKOBSERVER_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <mutex>
#include "taskperformerinterface.h"

using namespace std;

class TaskObserver
{
public:
    static TaskObserver& getInstance();

    void startTask(int id, TaskPerformerInterface* task);
    void endTask(int id, TaskPerformerInterface* task, long long int time);
private:
    TaskObserver();
    TaskObserver(const TaskObserver &other);
    mutex mtx;
    void printTime();
};

#endif // TASKOBSERVER_H
