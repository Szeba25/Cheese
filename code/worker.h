#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include "taskperformerinterface.h"
#include "taskobserver.h"

using namespace std;

class Worker
{
public:
    Worker(int id);
    ~Worker();

    void start();
    void join();
    void setTask(TaskPerformerInterface* task); // Function guarded by mutex
    bool isBusy(); // Function guarded by mutex

private:
    int id;
    thread* workerThread;

    TaskPerformerInterface* task; // Guarded by mutex
    bool killed; // Guarded by mutex

    mutex mtx;

    void work();
    void kill(); // Function guarded by mutex
    bool isKilled(); // Function guarded by mutex
};

#endif // WORKER_H
