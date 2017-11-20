#include "worker.h"

Worker::Worker(int id) :
    id(id),
    workerThread(nullptr),
    task(nullptr),
    killed(false)
{

}

Worker::~Worker()
{
    if (workerThread != nullptr) {
        delete workerThread;
    }
}

void Worker::start()
{
    workerThread = new thread(Worker::work, this);
}

void Worker::join()
{
    if (workerThread != nullptr) {
        kill();
        workerThread->join();
    }
}

void Worker::setTask(TaskPerformerInterface *task)
{
    mtx.lock();
        this->task = task;
    mtx.unlock();
}

bool Worker::isBusy()
{
    mtx.lock();
        bool result = (task != nullptr);
    mtx.unlock();
    return result;
}

void Worker::work()
{
    while (!isKilled()) {
        if (isBusy()) {
            auto begin = chrono::high_resolution_clock::now();
            TaskObserver::getInstance().startTask(id, task);
            task->execute();
            auto end = chrono::high_resolution_clock::now();
            TaskObserver::getInstance().endTask(id, task, (end-begin).count());
            setTask(nullptr);
        }
    }
}

void Worker::kill()
{
    mtx.lock();
        killed = true;
    mtx.unlock();
}

bool Worker::isKilled()
{
    mtx.lock();
        bool result = killed;
    mtx.unlock();
    return result;
}
