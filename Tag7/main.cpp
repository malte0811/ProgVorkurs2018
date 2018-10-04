#include <iostream>
#include "punkt.hpp"

int main() {
	Punkt<double> p(4);
	p[0] = 5;
	p[1] = -5;
	p[1] = 1;
	std::cout << p.getL1Norm() << ", " << p[0] << std::endl;
}
