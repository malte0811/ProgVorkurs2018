#include <limits>
#include "polynomial.hpp"
#include "mymath.hpp"

Polynomial::Polynomial(unsigned degree): _coeffs(degree+1) {}

Polynomial::Polynomial(std::initializer_list<double> coeffs): _coeffs(coeffs) {}

Polynomial::Polynomial(double a0): _coeffs{a0} {}

// Elementweise Summe. Achtung: Grad ist nicht Länge!
Polynomial Polynomial::operator+(const Polynomial& other) const {
	unsigned ownDegree = degree();
	unsigned otherDegree = other.degree();
	unsigned degree = max(ownDegree, otherDegree);
	Polynomial sum(degree);
	for (unsigned i = 0;i<=degree;++i) {
		if (i<=ownDegree) {
			sum[i] += (*this)[i];
		}
		if (i<=otherDegree) {
			sum[i] += other[i];
		}
	}
	return sum;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
	unsigned ownDegree = degree();
	unsigned otherDegree = other.degree();
	unsigned degree = ownDegree + otherDegree;
	Polynomial prod(degree);
	for (unsigned i = 0;i<=ownDegree;++i) {
		for (unsigned j = 0;j<=otherDegree;++j) {
			prod[i+j] += (*this)[i]*other[j];
		}
	}
	return prod;
}

double Polynomial::operator()(double x) const {
	double ret = 0;
	double potenz = 1;
	for (unsigned i = 0;i<=degree();++i) {
		ret += (*this)[i]*potenz;
		potenz *= x;
	}
	return ret;
}

double& Polynomial::operator[](int index) {
	return _coeffs[index];
}

const double& Polynomial::operator[](int index) const {
	return _coeffs[index];
}

unsigned Polynomial::degree() const {
	return _coeffs.size()-1;
}

Polynomial Polynomial::shift(double x, double y) {
	Polynomial ret(degree());
	for (unsigned i = 0;i<=degree();++i) {
		//Binomischer Lehrsatz: (a+b)^n = a^n+binomial(n, 1)*a^(n-1)*b+...+b^n
		double potenz = 1;
		for (unsigned j = i;j+1>0;--j) {//j>=0 geht nicht, da j unsigned ist. Der Standard garantiert aber, dass unsigned einfach modulo 2^n rechnet, also funktioniert j+1>0 immer
			ret[j] += binomial(i, j)*potenz*(*this)[i];
			potenz *= -x;//-x: Positives x soll nach rechts schieben
		}
	}
	ret[0] += y;
	return ret;
}

double Polynomial::limitAtInfinity(bool positiveInf) {
	for (unsigned i = degree();i>0;--i) {
		bool powerPositive = positiveInf or i%2==0;
		if ((*this)[i]!=0) {
			if (((*this)[i]>0)==powerPositive) {
				return std::numeric_limits<double>::infinity();
			} else {
				return -std::numeric_limits<double>::infinity();
			}
		}
	}
	return (*this)[0];
}

void printSigned(std::ostream& out, double d, bool printSign) {
	if (printSign and d>=0) {
		out << "+";
	}
	out << d;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
	for (unsigned i = p.degree();i>1;--i) {
		printSigned(out, p[i], i<p.degree());
		out << "*x^" << i;
	}
	if (p.degree()>0) {
		printSigned(out, p[1], p.degree()>1);
		out << "*x";
	}
	printSigned(out, p[0], p.degree()>0);
	return out;
}
