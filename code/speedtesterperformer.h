#ifndef SPEEDTESTERPERFORMER_H
#define SPEEDTESTERPERFORMER_H

#include <iomanip>
#include <sstream>
#include "taskperformerinterface.h"
#include "speedtester.h"

class SpeedTesterPerformer : public TaskPerformerInterface
{
public:
    SpeedTesterPerformer(double n1, double n2, char op, unsigned int count);
    virtual ~SpeedTesterPerformer();

    virtual void execute();
    virtual string getDescription() const;
    virtual string getResult() const;
private:
    SpeedTester* speedTester;
    SpeedTester::time_measure time;
    double n1, n2;
    char op;
    unsigned int count;
};

#endif // SPEEDTESTERPERFORMER_H
