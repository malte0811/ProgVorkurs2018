#include <iostream>

/*Cosinus-Reihe*/
// Definiert für pi <= x <= pi im Bogenmaß

int main () {
	// Variablen-Deklaration
	double summe, summand;
	double x;
	
	// Variablen-Initialisierung
	//x=1.5708;
	x = 1;			// Zahl von der der Cosinus berechnet wird (keine Eingabe in Konsole)
	summe = 0;		// Initialisiert um += verwenden zu können
	summand = 1;	// Erster Summand per Hand berechnet um Teilen durch 0 zu umgehen
	
	
	// Berechnung mit Wiederverwendung der alten Summanden(effizienter, aber minimal ungenauer)
	for  (int n=1; summand > 1e-15 || summand < -1e-15; ++n) 
		// Überprüfe nicht auf eine gewisse Anzahl an Iterationen stattdessen auf
		// eine gewisse Genauigkeit, damit werden nie zu viele Iterationen durchgeführt 
		// was Überläufe bei wachsenden Zahlen verhindert
	{
		summe +=  summand;
		summand *= -x*x/(2*n*(2*n-1));
	}
	
	std::cout << "cos(" << x << ") = " << summe << std::endl;
	return 0;
}


/* Bemerkung zu alternativen Implementierungen:
	Man kann auch jeden Summeanden neu berechnen ohne den alten Summanden zu verwenden.
	Dann sind Funktionen für Fakultät und Potenz sinnvoll, dabei ist zu beachten,
	dass int schnell "zu klein" für Fakultäten wird, andere Datentypen wie long passen besser */
/* Weitere Fehler:
	- Zu viele oder wenige Iterationen bei Fakultät oder Potenz
	- Rückgabewerte von Potenz müssen double sein, da auch Doubles eingegeben werden 
	- Manche haben mit if (n % 2){} gearbeitet, beachte dass der Block ausgeführt wird wenn n ungerade ist*/
