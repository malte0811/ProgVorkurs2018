#include <iostream>

int main() {
	int eingabe;
	std::cout << "Bitte zu prüfende Zahl eingeben: ";
	std::cin >> eingabe;
	if (not std::cin or eingabe<2) {
		std::cout << "Eingabe war keine gültige Zahl!" << std::endl;
		return 1;
	}
	bool istPrim = true;
	for (int teiler = 2;teiler*teiler<=eingabe and istPrim;teiler++) {
		if (eingabe%teiler==0) {
			istPrim = false;
		}
	}
	std::cout << eingabe << " ist ";
	if (!istPrim) {
		std::cout << "nicht ";
	}
	std::cout << "prim" << std::endl;
	return 0;
}
