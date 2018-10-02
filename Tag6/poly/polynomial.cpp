#include <limits>
#include "polynomial.hpp"
#include "mymath.hpp"

Polynomial::Polynomial(unsigned degree): _coeffs(degree+1) {}

Polynomial::Polynomial(std::initializer_list<double> coeffs): _coeffs(coeffs) {}

Polynomial::Polynomial(double a0): _coeffs{a0} {}

Polynomial Polynomial::operator+(const Polynomial& other) const {
	unsigned degreeThis = degree();
	unsigned degreeOther = other.degree();
	unsigned degreeRet = max(degreeThis, degreeOther);
	Polynomial ret(degreeRet);
	for (unsigned i = 0;i<=degreeRet;++i) {
		ret[i] = (*this)[i]+other[i];
	}
	return ret;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
	unsigned degreeThis = degree();
	unsigned degreeOther = other.degree();
	unsigned degreeRet = degreeThis+degreeOther;
	Polynomial ret(degreeRet);
	for (unsigned i = 0;i<=degreeThis;++i) {
		for (unsigned j = 0;j<=degreeOther;++j) {
			ret[i+j] += (*this)[i]*other[j];
		}
	}
	return ret;
}

double& Polynomial::operator[](int index) {
	if (index>degree()) {
		return 0;
	}
	return _coeffs[index];
}

const double& Polynomial::operator[](int index) const {
	return _coeffs[index];
}

unsigned Polynomial::degree() const {
	return _coeffs.size()-1;
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

Polynomial Polynomial::shift(double p) {
	Polynomial ret(degree());
	for (unsigned i = 0;i<=degree();++i) {
		double potenz = 1;
		for (unsigned j = 0;j<=i;++j) {
			ret[i-j] += binomial(i, j)*potenz;
			potenz *= p;
		}
	}
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
