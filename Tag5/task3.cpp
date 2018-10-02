#include "mymath.hpp"
#include <iostream>
#include <limits>

double zeta(double s)
{
	if(s <= 1) return std::numeric_limits<double>::infinity();
	
	double sum = 0;
	double summand = 1;
	for(int k = 1; summand > 1e-10 || summand < -1e-10; ++k)
	{
		summand = pow(k,-s);
		sum += summand;
	}
	
	return sum;
}

int main()
{
	std::cout << zeta(2) << std::endl;
}
