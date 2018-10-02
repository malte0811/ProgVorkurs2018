#include <iostream>
#include <vector>
#include <cmath> // für Logarithmusfunktion

std::vector<int> primvec (int n){
	
	// Ein Vector mit Bools dessen ite Stelle angibt ob i eine Primzahl ist
	std::vector<bool> bools(n+1,true);
	std::vector<int> primzahlen (0);
	primzahlen.reserve(n/log(n)*(1+1.2762/log(n))); // Obere Schranke für Anzahl der Primzahlen bis n
													// Reserve bewirkt, dass entsprechend viel Speicher schonmal reserviert wird
	bools[0]=false;		// Der Vollständigkeit halber
	bools[1]=false;		// 	"		"			"
	for (int i=2; i <=n ; i++){
		if (bools[i]){
			primzahlen.push_back(i);			// Fügt eine gefundene Primzahl dem Ergebniss zu
			for (int k = 2; k <= n/i ; k++){	// Speichere alle Vielfachen als "nicht Prim" ab
				bools[i*k]=false;
			}
		}
	}
	
	return primzahlen;
}


int main (){
	int n = 200000000;
	std::vector<int> primzahlen = primvec(n);
	
	// Ausgabe des Vectors
	for (unsigned i=0; i < primzahlen.size() ; i++){
		std::cout << primzahlen[i] << " ";
	}
	std::cout<< std::endl;
	
	return 0;
}
