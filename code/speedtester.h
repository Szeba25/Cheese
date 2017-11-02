#ifndef SPEEDTESTER_H
#define SPEEDTESTER_H

#include <chrono>

using namespace std;

class SpeedTester
{
	double number1, number2;
	char operation;
	unsigned int count;
public:
	typedef chrono::duration<double, std::milli> time_measure; // Just a typedef

	SpeedTester(double n1, double n2, char op, unsigned int count);
	double getNumber1() const;
	double getNumber2() const;
	char getOperation() const;
	unsigned int getCount() const;

	time_measure test() const; // The function that performs the test
};

#endif // SPEEDTESTER_H
