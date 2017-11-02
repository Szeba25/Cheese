#ifndef TASKPERFORMERINTERFACE_H
#define TASKPERFORMERINTERFACE_H

#include <string>

using namespace std;

class TaskPerformerInterface
{
public:
	virtual ~TaskPerformerInterface(); // Because it is an abstract class

	virtual void execute() = 0; // The function to execute the task
	virtual string getDescription() const = 0; // Returns a description of the task as a string
	virtual string getResult() const = 0; // Returns the result of the task as a string
};

#endif // TASKPERFORMERINTERFACE_H
