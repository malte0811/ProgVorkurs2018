#include <iostream>

int main() {
	int eingabe;
	std::cout << "Bitte Anfangswert eingeben: ";
	std::cin >> eingabe;
	if (not std::cin or eingabe<2) {
		std::cout << "Eingabe war keine gültige Zahl!" << std::endl;
		return 1;
	}
	bool istPrim = false;
	while (not istPrim) {
		istPrim = true;
		for (int teiler = 2;teiler*teiler<=eingabe and istPrim;++teiler) {
			if (eingabe%teiler==0) {
				istPrim = false;
			}
		}
		if (not istPrim) {
			++eingabe;
		}
	}
	std::cout << "Die nächste Primzahl ist " << eingabe << std::endl;
	return 0;
}
