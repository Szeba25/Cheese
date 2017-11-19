#include "taskcontainer.h"

TaskContainer::TaskContainer()
{
    ifstream file("tasklist.txt");
    string data;
    bool completed = false;
    if (file.is_open()) {
        while (file.good() && !completed) {
            file >> data;
            if (data == "*") {
                completed = true;
            } else if (data == "fibonacci") {
                int number;
                file >> number;
                //cout << number << endl;
                tasks.push_back(new FibonacciPerformer(number));
            } else if (data == "speedtest") {
                double n1, n2;
                char op;
                int count;
                file >> n1 >> op >> n2 >> count;
                //cout << n1 << " " << op << " " << n2 << " " << count << endl;
                tasks.push_back(new SpeedTesterPerformer(n1, n2, op, count));
            } else if (data == "readlog") {
                string fileName;
                file >> fileName;
                //cout << fileName << endl;
                tasks.push_back(new LogReaderPerformer(fileName));
            }
        }
        file.close();
    } else {
        cout << "ERROR: Missing tasklist.txt file" << endl;
    }
    currentTask_it = tasks.begin();
}

TaskContainer::~TaskContainer()
{
    for (TaskPerformerInterface*& task : tasks) {
        delete task;
    }
}

TaskPerformerInterface *TaskContainer::getNextTask()
{
    if (currentTask_it == tasks.end()) {
        return nullptr;
    } else {
        list<TaskPerformerInterface*>::iterator it = currentTask_it;
        currentTask_it++;
        return *it;
    }
}

void TaskContainer::saveOutput()
{
    ofstream file("output.txt");
    if (file.is_open()) {
        for (TaskPerformerInterface*& task : tasks) {
            file << endl << "Task description: " << task->getDescription() << endl;
            file << "Result:" << endl;
            file << task->getResult() << endl;
            file << "---------------------------------" << endl;
        }
    }
    file.close();
}
