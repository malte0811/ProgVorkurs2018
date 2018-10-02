#include <iostream>
#include <cmath>	// für Betragsfkt.

// Klasase für Brüche (Achtung durch Null teilen wird nicht abgefangen)
class Bruch {
public:
	// ---------- Konstruktor ----------
	Bruch(int zaehler, int nenner){
      _zaehler = zaehler;
      _nenner = nenner;
	}

	// ---------- Getter ----------
	int get_zaehler() const{
		return _zaehler;
	}

	int get_nenner() const{
		return _nenner;
	}
	
	// ---------- Setter----------
	void set_zaehler(int zaehler){
		_zaehler = zaehler;
	}

	void set_nenner(int nenner){
		_nenner = nenner;
	}
	
	// ---------- Funktionen ----------
	void print(){
		std::cout << _zaehler << " / " << _nenner << std::endl;
	}

	Bruch multiplizieren (const Bruch & bruch) const{
		return Bruch(_zaehler * bruch.get_zaehler(),
                   _nenner * bruch.get_nenner());	
	}
	
	Bruch addieren (const Bruch & bruch) const{
		
		return Bruch(_zaehler * bruch.get_nenner() + bruch.get_zaehler() * _nenner,
                   _nenner * bruch.get_nenner());	
	}
	
	Bruch& kuerze(){	// Gibt den gekürzten Bruch als Referenz zurück
		int a = abs(_zaehler);		// Euklidischer ALgorithmus nur
		int b = abs(_nenner);		// für positive Zahlen definiert
		int divisor;
		// Euklidischer Algorithmus	
		if(a == 0) {
			divisor = b;
		}
		else {
			while (b != 0) {
				if (a > b) a -= b;
				else b -= a;
			}
			divisor = a;
		}
		_zaehler /= divisor;
		_nenner /= divisor;
		return *this;
	}

private:
	int _zaehler;
	int _nenner;
};

	int main(){
	Bruch a(17, 15);
	Bruch b(2, 15);
	Bruch c(15, 2);
	
	a.addieren(b).print();
	a.addieren(b).kuerze().print();
	b.multiplizieren(c).kuerze().print();
	
	return 0;
	
}
