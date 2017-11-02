#include "fibonacci.h"

unsigned long long int Fibonacci::getFibo(unsigned int n)
{
	if (n==0) return 0;
	else if (n==1) return 1;
	else return getFibo(n-1) + getFibo(n-2);
}
