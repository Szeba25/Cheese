#include "fibonacciperformer.h"

FibonacciPerformer::FibonacciPerformer(int number) :
    number(number),
    fibonacciNumber(0)
{
}

FibonacciPerformer::~FibonacciPerformer()
{
}

void FibonacciPerformer::execute()
{
    fibonacciNumber = Fibonacci::getFibo(number);
}

string FibonacciPerformer::getDescription() const
{
    stringstream ss;
    ss << "fibonacci, number: " << number;
    return ss.str();
}

string FibonacciPerformer::getResult() const
{
    return to_string(fibonacciNumber);
}
