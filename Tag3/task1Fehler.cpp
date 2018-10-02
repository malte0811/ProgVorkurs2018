
#include  <iostream>

int  fakultaet (int n){		// Fehler 1: Typ fehlt
	int  ergebnis = 1;     	// Fehler 2: 0 mal irgendwas ist 0
	while (n > 0){          // Fehler 3: Geschweifte Klammern fehlten
		ergebnis  *= n;     
		n--;                
	}
	return  ergebnis;
}

int  main (){
		int  add2fak;
		const  int a = 5;
		const  int b = 16;
	
		add2fak = fakultaet (a) + fakultaet (b);		// Fehler 4:Tippfehler in fakultaet
		std::cout  << a << "! + " << b << "! = " << add2fak  << std::endl; 
							// Fehler 5: "<<" fehlte
		return 0;			// Fehler 6: "," anstat ";"
}
