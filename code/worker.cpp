#include "worker.h"

Worker::Worker()
{

}

void Worker::setTask(TaskPerformerInterface* task)
{
    this->task = task;
}

void Worker::doTask()
{
    task->execute();
}
