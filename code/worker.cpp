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

void Worker::reg(TaskObserver* observer)
{
    taskObserver = observer;
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
            taskObserver->startTask(id, task);
            chrono::system_clock::time_point begin = chrono::high_resolution_clock::now();
            task->execute();
            chrono::system_clock::time_point end = chrono::high_resolution_clock::now();
            chrono::duration<long long int, std::nano> elapsed = (end-begin);
            taskObserver->endTask(id, task, elapsed);
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
