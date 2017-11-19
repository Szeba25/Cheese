#ifndef FIBONACCIPERFORMER_H
#define FIBONACCIPERFORMER_H

#include <sstream>
#include "taskperformerinterface.h"
#include "fibonacci.h"

using namespace std;

class FibonacciPerformer : public TaskPerformerInterface
{
public:
    FibonacciPerformer(int number);
    virtual ~FibonacciPerformer();

    virtual void execute();
    virtual string getDescription() const;
    virtual string getResult() const;
private:
    unsigned int number;
    unsigned long long int fibonacciNumber;
};

#endif // FIBONACCIPERFORMER_H
