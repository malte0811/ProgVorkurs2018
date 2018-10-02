#include <iostream>

double powRekursiv(double a, int b) {
	if ( b == 0) {
		return 1;
	} else if (b%2==0) {
		return powRekursiv(a*a, b/2);
	} else {
		return a*powRekursiv(a*a, (b-1)/2);
	}
}

double powNaiv(double a, int b) {
	double ret = 1;
	for (int i = 0;i<b;i++) {
		ret *= a;
	}
	return ret;
}

double powIterativ(double a, int b) {
	double ret = 1;
	while (b>0) {
		if (b%2==1) {
			ret *= a;
		}
		b /= 2;
		a *= a;
	}
	return ret;
}

int main() {
	const double a = 0.9999999999;
	const int b = 2000000000;
	std::cout.precision(17);//Mehr Nachkommastellen ausgeben, sonst wird a als 1 augegeben
	std::cout << a << "^" << b << "=" << powRekursiv(a, b) << " (Rekursiv)" << std::endl;
	std::cout << a << "^" << b << "=" << powNaiv(a, b) << " (Naiv)" << std::endl;
	std::cout << a << "^" << b << "=" << powIterativ(a, b) << " (Iterativ)" << std::endl;
}
