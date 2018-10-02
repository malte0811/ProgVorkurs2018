#include <iostream>

int main() {
	double precision;
	std::cout << "Bitte Präzision eingeben: ";
	std::cin >> precision;
	if (not std::cin or precision<=0) {
		std::cout << "Ungültige Eingabe" << std::endl;
		return 1;
	}
	double lastAdded;
	double sum = 0;
	int n = 1;
	do {
		lastAdded = 1./(n*n);
		++n;
		sum += lastAdded;
	} while (lastAdded>precision);
	std::cout << "Reached value " << sum << " with " << n << " iterations" << std::endl;
	return 0;
}
