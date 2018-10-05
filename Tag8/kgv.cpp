#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
/**
 * Berechnet den größten gemeinsamen Teiler von a und b
 */
unsigned ggT(unsigned a, unsigned b) {
	while (a>0 and b>0) {
		if (a>b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	if (a>0) {
		return a;
	} else {
		return b;
	}
}

/**
 * Berechnet das kleinste gemeinsame Vielfache von a und b.
 * Die genutzte Formel folgt aus der Primfaktorzerlegung
 * (kann aber vermutlich auch ohne diese gezeigt werden)
 */
unsigned kgV(unsigned a, unsigned b) {
	return (a/ggT(a, b))*b;
}

/**
 * Berechnet das kleinste gemeinsame Vielfache aller in `in`
 * gespeciherter Zahlen.
 */
unsigned kgV(const std::vector<unsigned>& in) {
	if (in.size()==0) {
		return 1;
	}
	unsigned kgVBisI = in[0];
	for (unsigned i = 1;i<in.size();++i) {
		//kgVBisI ist das kgV der ersten i-1 Zahlen, das kgV der ersten i Zahlen muss durch dieses und in[i] teilbar sein
		//(und dabei minimal)
		kgVBisI = kgV(kgVBisI, in[i]);
	}
	return kgVBisI;
}

int main(int argc, char** argv) {
	if (argc<2) {
		std::cout << "Keine Eingabedatei!" << std::endl;
		return 1;
	}
	std::ifstream in(argv[1]);
	if (!in) {
		std::cout << "Ungültige Eingabedatei!" << std::endl;
		return 1;
	}
	std::string line;
	std::vector<unsigned> data;
	while (std::getline(in, line)) {
		std::stringstream lineStream(line);
		unsigned num;
		lineStream >> num;
		if (!lineStream) {
			std::cout << "Ungültige Daten in Eingabedatei!" << std::endl;
			return 1;
		}
		data.push_back(num);
	}
	in.close();
	std::cout << "Kleinstes gemeinsames Vielfaches: " << kgV(data) << std::endl;
}
