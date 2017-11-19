#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include "taskperformerinterface.h"

using namespace std;

class Worker
{
public:
    Worker();

    void setTask(TaskPerformerInterface* task);
    void doTask();
private:
    TaskPerformerInterface* task;
};

#endif // WORKER_H
