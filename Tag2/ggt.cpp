#include <iostream>

int main() {
	int a, b;
	std::cout << "Bitte zwei nichtnegative ganze Zahlen eingeben" << std::endl;
	std::cin >> a >> b;
	if (not std::cin or a<0 or b<0) {
		std::cout << "Ungültige Eingabe!" << std::endl;
		return 1;
	}
	while (a>0 and b>0) {
		if (a>b) {
			a -= b;
		} else {
			b -= a;
		}
	}
	if (a>0) {
		std::cout << "ggT der Eingaben ist " << a << std::endl;
	} else {
		std::cout << "ggT der Eingaben ist " << b << std::endl;
	}
	return 0;
}
