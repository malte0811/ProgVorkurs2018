#include "mymath.hpp"

unsigned binomial(unsigned n, unsigned k) {
	unsigned sol = 1;
	for(unsigned i = 1; i <= k; ++i) {
		sol *= (n-i+1);
		sol /= (i);
	}
	return sol;
}

unsigned max(unsigned a, unsigned b) {
	if (a>b) {
		return a;
	} else {
		return b;
	}
}

unsigned min(unsigned a, unsigned b) {
	if (a<b) {
		return a;
	} else {
		return b;
	}
}


double exp(double x) {
	double sum = 0;
	double lastSummand = 1;
	for (int k = 0;lastSummand>1e-10 or lastSummand<-1e-10;++k) {
		sum += lastSummand;
		lastSummand *= x/(k+1);
	}
	return sum;
}

double log(double x) {
	double sum = 0;
	double ersterTeil = (x-1)/(x+1);
	double factor = ersterTeil*ersterTeil;
	double summand = 1;
	for (int k = 0;summand<-1e-10 || summand>1e-10;++k) {
		summand = ersterTeil/(2*k+1);
		sum += summand;
		ersterTeil *= factor;
	}
	return 2*sum;
}

double pow(double x, double y) {
	return exp(y*log(x));
}
