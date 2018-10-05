#include <iostream>		// für Ausgaben
#include <fstream>		// fürs Dateineinlesen
#include <vector>		// für Vectoren
#include <limits>		// für Max/Min-Werte
#include <sstream>		// fürs Stringauswerten
#include <ctime>		// fürs Zeitmessen

// Struct (Klasse ohne Funktionen) um Rechtecke besser verwalten zu können
typedef struct rechteck {
	int x_min;
	int x_max;
	int y_min;
	int y_max;
}rechteck; // Ohne typedef müsste man immer struct::rechteck schreiben


void ZweiD (std::string dateiname, int skalierung){

	std::ifstream datei(dateiname);	// Ermöglicht Einlesen aus der Datei mittels getline()
	if(not  datei){
		std::cout  << "Keine  Datei " << dateiname  << " gefunden." << std::endl;
		return;
	}
	// Vorinitialisierung der Werte zur Bestimmung der Arraygröße
	int xmin = std::numeric_limits<int>::max();
	int xmax = std::numeric_limits<int>::min();
	int ymin = std::numeric_limits<int>::max();
	int ymax = std::numeric_limits<int>::min();
	std::string zeile;
	std::vector<rechteck> flaechen;	// Vector um die eingelesenden Rechtecke zu speichern
	
	// Liest nacheinander alle Zeilen der Datei ein
	while(std:: getline(datei , zeile)){
		rechteck aktuell;
		std::stringstream ss(zeile);	// Ermöglicht Auswerten das Strings als Integer
		ss>>aktuell.x_min>>aktuell.x_max>>aktuell.y_min>> aktuell.y_max;
		
		aktuell.x_min *=skalierung;
		aktuell.y_min *=skalierung;
		aktuell.x_max *=skalierung;
		aktuell.y_max *=skalierung;
		
		if (aktuell.x_min < xmin) xmin= aktuell.x_min;
		if (aktuell.y_min < ymin) ymin= aktuell.y_min;
		if (aktuell.x_max > xmax) xmax= aktuell.x_max;
		if (aktuell.y_max > ymax) ymax= aktuell.y_max;
		flaechen.push_back(aktuell);	// Fügt eingelesendes Rechteck dem Vector hinzu
	}
	
	// Nötige Länge des Vektors
	int xdiff = xmax-xmin +1;
	int ydiff = ymax-ymin +1;
	// Zwei dimensionaler Vector
	std::vector<std::vector<bool>> xAchse (xdiff, std::vector<bool>(ydiff,true));
		
	for( auto ecke : flaechen){	// Geht alle Rechtecke im Vector durch
		for (int i=ecke.x_min; i <= ecke.x_max; i++){
			for (int j = ecke.y_min; j <= ecke.y_max; j++){
				// Testet ob die Fläche des Rechtecks noch frei ist und speichert sie als belegt falls noch nicht
				if (xAchse[i-xmin][j-ymin]) xAchse[i-xmin][j-ymin] = false;	
				else {
					std::cout << "Überschneidung in " << i << " " << j << std::endl;
					return;
				}
			}
		}
	}
	std::cout << "Ueberschneidungsfrei" << std::endl;
	return;
}

void kleiner (std::string dateiname){
	
	std::vector<rechteck> flaechen;
	std::ifstream datei(dateiname);
	if(not  datei){
		std::cout  << "Keine  Datei " << dateiname  << " gefunden." << std::endl;
		return;
	}
	
	std::string zeile;
	
	while(std:: getline(datei , zeile)){
		std::stringstream ss(zeile);	// 
		rechteck aktuell;
		ss>>aktuell.x_min>>aktuell.x_max>>aktuell.y_min>> aktuell.y_max;
		flaechen.push_back(aktuell);
	}
	// Testet ob die Eckpunkte eines Rechtecks innerhalb eines der folgenden Rechtecke liegen	
	for (unsigned i = 0; i < flaechen.size();i++){
		rechteck const & aktuell = flaechen[i];
		for (unsigned j = i+1; j < flaechen.size();j++){
			rechteck const & vergleich = flaechen[j];
			// Reihenfolge der Vergleiche macht einen Unterschied bei unseren Instanzen
			if (aktuell.x_max >= vergleich.x_min && aktuell.y_max >= vergleich.y_min &&
				aktuell.x_min <= vergleich.x_max && aktuell.y_min <= vergleich.y_max){
					std::cout << "Überschneidung in max(" << aktuell.x_min << "," 
					<< vergleich.x_min << ") und max(" << aktuell.y_min << "," 
					<< vergleich.y_min << ")"<<  std::endl;
					return;
					}
		}
	} 

	std::cout << "Ueberschneidungsfrei" << std::endl;
	return;
}


int main (int count, char ** args){
	if(count  <= 1){
		std::cout  << "Kein  Dateiname  eingegeben" << std::endl;
		return  0;
	}
	clock_t zeit1, zeit2, zeit3, zeit4;		// Variablen zur Zeitmessung
	zeit1 = clock();
	std::cout << "Berechnung mit Vektorfeld... ";
	std::cout.flush();
	ZweiD (args [1],1);
	zeit2 = clock();
	std::cout << "Berechnung dauerte " << static_cast<double>(zeit2-zeit1)/ CLOCKS_PER_SEC << " Sekunden"<< std::endl;
	//std::cout << "Berechnung mit Vektorfeld (Skaliert mit 20)... "<< std::flush;
	//ZweiD (args [1],20);
	zeit3 = clock();
	//std::cout << "Berechnung dauerte " << static_cast<double>(zeit3-zeit2)/ CLOCKS_PER_SEC << " Sekunden"<< std::endl;
	std::cout << "Berechnung durch einzelne Tests... "<< std::flush;
	kleiner(args [1]);
	zeit4 = clock();
	std::cout << "Berechnung dauerte " << static_cast<double>(zeit4-zeit3)/ CLOCKS_PER_SEC << " Sekunden"<< std::endl;
		
	return 0;
}
	
