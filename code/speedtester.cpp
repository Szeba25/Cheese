#include "speedtester.h"

SpeedTester::SpeedTester(double n1, double n2, char op, unsigned int count):
	number1(n1),
	number2(n2),
	operation(op),
	count(count)
{
}

double SpeedTester::getNumber1() const
{
	return number1;
}

double SpeedTester::getNumber2() const
{
	return number2;
}

char SpeedTester::getOperation() const
{
	return operation;
}

unsigned int SpeedTester::getCount() const
{
	return count;
}

SpeedTester::time_measure SpeedTester::test() const
{
	chrono::system_clock::time_point t1 = chrono::high_resolution_clock::now();
	double res;
	if (operation == '*')
	{
		for (unsigned int i=1; i<count; i++)
			res=number1*number2;
	}
	else if (operation == '/')
	{
		for (unsigned int i=1; i<count; i++)
			res=number1/number2;
	}
	else if (operation == '+')
	{
		for (unsigned int i=1; i<count; i++)
			res=number1+number2;
	}
	else if (operation == '-')
	{
		for (unsigned int i=1; i<count; i++)
			res=number1-number2;
	}
	chrono::system_clock::time_point t2 = chrono::high_resolution_clock::now();
	return t2-t1;
}
