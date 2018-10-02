#include <iostream>

// Sammlung verschiedener Funktionen 

//  Cosinusfunktion über Reihendarstellung definiert für pi <= x <= pi (Bogenmaß)
double cosinus (double x){
	if (x < -4 or x > 4){
		std::cout << "(Achtung es können Ungenauigkeiten auftreten sein) ";
	}

	double summe, summand;
	summe = 0;		
	summand = 1;	
	
	for  (int n=1; summand > 1e-15 || summand < -1e-15; ++n) 
	{
		summe +=  summand;
		summand *= -x*x/(2*n*(2*n-1));
	}
	return summe;
}

// Betragsfunktion für reelle Zahlen
double betrag (double x){
	if (x < 0) {
		return -x;
	}
	else {
		return x;
	}
}

// Wurzelfunktion für reelle Zahlen
double wurzel(double a){
	double x,y;	
	x = 2;
	y = 1;
	while ((x-y) > 10e-10 or (x-y) < -10e-10){ // Test beider Richtungen entspricht Betrag
												// e-Notation steht für 10^-10
		x = y;
		y = 0.5 *(x+(a/x));		// Häufiger Fehler: 1/2=0 da es Integer sind
	}
	
	return x;
}


int main () {
	double x = -1;
	std::cout << "Betrag von " << x << " = " << betrag(x) << std::endl;
	std::cout << "Wurzel von " << 625 << " ist " << wurzel(625) << std::endl;
	std::cout << "cos(" << x << ") = " << cosinus(x) << std::endl;
	return 0;
}

