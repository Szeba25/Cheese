#include "speedtesterperformer.h"

SpeedTesterPerformer::SpeedTesterPerformer(double n1, double n2, char op, unsigned int count) :
    n1(n1), n2(n2), op(op), count(count)
{
    speedTester = new SpeedTester(n1, n2, op, count);
}

SpeedTesterPerformer::~SpeedTesterPerformer()
{
    delete speedTester;
}

void SpeedTesterPerformer::execute()
{
    time = speedTester->test();
}

string SpeedTesterPerformer::getDescription() const
{
    stringstream ss;
    ss << fixed;
    ss << setprecision(6);
    ss << "speed test, numbers: " << n1 << ", " << n2 << ", operation: " << op << ", iterations: " << count;
    return ss.str();
}

string SpeedTesterPerformer::getResult() const
{
    stringstream ss;
    ss << fixed;
    ss << setprecision(6);
    ss << time.count() << " milliseconds (" << (count/(time.count()))/1000 << " million operations per second)";
    return ss.str();
}
