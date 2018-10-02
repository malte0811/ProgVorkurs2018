#include  <iostream>

#include  <vector>


/*  Liefert  das  Maximum  einer  Menge  von  nichtnegativen  Zahlen.
Wenn  keine  Zahlen  gegeben  werden , ist  die   Ausgabe  0. */

unsigned  maximum(const  std::vector <unsigned> & zahlen){
	unsigned  result = 0;
	for(unsigned i = 0; i < zahlen.size(); ++i){	// Fehler 1: Klammern bei size fehlten
		if(zahlen[i] > result){
			result = zahlen[i];
		}
	}
	return  result;
}


int  main(){
	std::vector <unsigned> eintraege;				// Fehler 2: Datentyp geändert damit mit Funktion oben übereinstimmt
	std::cout  << "Geben  Sie nicht -negative  Zahlen  ein. " << std::endl;
	std::cout  << "Mit  einer  negativen  Zahl  koennen  Sie  die  Eingabe  beenden"   << std::endl;
	int eingabe;									// Fehler 3: Variable muss außerhalb der Schleife deklariert 
													// werden, damit in Bedingung überprüft werden kann
	do{
		std::cout  << "Naechster  Eintrag  bitte. ";
		std::cin   >> eingabe;
		if(eingabe  >= 0){
			eintraege.push_back(eingabe );			// Fehler 4: Funktion heißt push_back
													// Beachte, dass hier ein automatischer Typecast stattfindet
		}
	} while(eingabe  >= 0);							// Fehler 5:Semikolon am Zeilenende fehlte 
	if(eintraege.size() > 0){
		int  groesste_zahl = maximum(eintraege );	// Fehler 5.5: unsigned wäre hier besser
		std::cout  << "Das  Maximum  ist: " << groesste_zahl  << std::endl;
	}
	return  0;
}


