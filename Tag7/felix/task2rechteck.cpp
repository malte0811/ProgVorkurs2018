#include "rechteck.hpp"
#include <iostream>


int main(){
	
	Dimension dim;
	dim = x_dim;
	//dim = 1; // Fehler
	//array[dim]; // = array[0]
	
	try{
		Rechteck wuerfel(2,4,2,4);
		wuerfel.print();
		wuerfel.set_max(-3,x_dim);
		wuerfel.print();
	}
	catch(std::string fehlermeldung){
		
		std::cout << "Test1 " << fehlermeldung << std::endl;
	}
	
	try{
		Rechteck falsch(6,4,6,4);
		falsch.print();
	}
	catch(char const * fehlermeldung){
		
		std::cout << "Test2 " << fehlermeldung << std::endl;
	}
	
	return 0;
}

