#include <iostream>
#include <thread>
#include <list>
#include "speedtester.h"
#include "fibonacci.h"
#include "logreader.h"
#include "taskperformerinterface.h"
#include "taskcontainer.h"
#include "worker.h"

using namespace std;

int main()
{
    TaskContainer taskContainer;

    unsigned int n = thread::hardware_concurrency();
    if (n < 3) n = 3;
    if (n > 8) n = 8;
    int maxThreads = n-1;

    list<Worker*> workers;

    for (int i = 0; i < maxThreads; i++) {
        workers.push_back(new Worker(i));
    }

    cout << "Executing on " << maxThreads << " number of threads" << endl << endl;
    for (Worker*& w : workers) {
        w->reg(&TaskObserver::getInstance());
        w->start();
    }

    TaskPerformerInterface* task = taskContainer.getNextTask();
    while (task != nullptr) {
        for (Worker*& w : workers) {
            if (!w->isBusy()) {
                w->setTask(task);
                task = taskContainer.getNextTask();
                break;
            }
        }
    }

    for (Worker*& w : workers) {
        w->join();
        delete w;
    }

    taskContainer.saveOutput();

	return 0;
}
