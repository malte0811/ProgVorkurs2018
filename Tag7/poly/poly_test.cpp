#include <vector>
#include <iostream>
#include "polynomial.hpp"

int main() {
	Polynomial<int> p{-1, 1};//Achtung: links steht der Koeffizient für x^0
	std::cout << p(2) << ", " << p[2] << std::endl;
	p = p*p;
	std::cout << p << std::endl;
}
