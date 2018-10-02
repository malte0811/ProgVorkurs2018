#include <iostream>

int main() {
	double input;
	std::cout << "Bitte nichtnegative Zahl eingeben: ";
	std::cin >> input;
	if (not std::cin or input<0) {
		std::cout << "Ungültige Eingabe!" << std::endl;
		return 1;
	}
	double currentApprox = 2;
	double changeFromLast = 1;
	while (changeFromLast>1e-10 or changeFromLast < -1e-10) {
		double oldVal = currentApprox;
		currentApprox = .5*(currentApprox+input/currentApprox);
		changeFromLast = currentApprox-oldVal;
	}
	std::cout << "Wurzel von " << input << " ist etwa " << currentApprox << std::endl;
	return 0;
}
