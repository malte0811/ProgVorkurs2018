#include <vector>
#include <iostream>
#include "polynomial.hpp"

int main() {
	Polynomial p{1, 2, 1};//Achtung: links steht der Koeffizient für x^0
	std::cout << p(2) << ", " << p[2] << std::endl;
	p = p+-15;
	std::cout << p << std::endl;
}
