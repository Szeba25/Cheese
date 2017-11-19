#ifndef TASKCONTAINER_H
#define TASKCONTAINER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "taskperformerinterface.h"
#include "fibonacciperformer.h"
#include "speedtesterperformer.h"
#include "logreaderperformer.h"

using namespace std;

class TaskContainer
{
public:
    TaskContainer();
    ~TaskContainer();

    TaskPerformerInterface* getNextTask();
    void saveOutput();
private:
    list<TaskPerformerInterface*> tasks;
    list<TaskPerformerInterface*>::iterator currentTask_it;
};

#endif // TASKCONTAINER_H
