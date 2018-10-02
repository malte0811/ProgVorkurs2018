#include  <iostream>
int  array_sum(int* array ,unsigned length){
						// Fehler 1: Datentyp eines Arrays ist int*
	int  sum = 0;
	for (unsigned i = 0; i  < length; ++i){
						// Fehler 2: Arrayeinträge gehen von 0 bis n-1
		sum +=  array[i];
	}
	return  sum;
}

int  main(){
	int a[6] = { 3, 12, 1, 3, 7, 21 };
	std::cout  << array_sum(a,6)  << std::endl;
						// Optional: return 0; fehlt
}
