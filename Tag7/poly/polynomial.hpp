#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include <vector>
#include <ostream>
#include <initializer_list>
#include "mymath.hpp"

template<typename T>
class Polynomial {
public:
	explicit Polynomial(unsigned degree);
	explicit Polynomial(std::initializer_list<T> coeffs);
	Polynomial(T);
	Polynomial operator+(const Polynomial& other) const;
	Polynomial operator*(const Polynomial& other) const;
	T operator()(T x) const;
	T& operator[](int index);
	const T& operator[](int index) const;
	unsigned degree() const;
	Polynomial shift(T x);
private:
	std::vector<T> _coeffs;
};
template<typename T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& p);


template<typename T>
Polynomial<T>::Polynomial(unsigned degree): _coeffs(degree+1) {}

template<typename T>
Polynomial<T>::Polynomial(std::initializer_list<T> coeffs): _coeffs(coeffs) {}

template<typename T>
Polynomial<T>::Polynomial(T a0): _coeffs{a0} {}

template<typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial& other) const {
	unsigned degreeThis = degree();
	unsigned degreeOther = other.degree();
	unsigned degreeRet = max(degreeThis, degreeOther);
	Polynomial ret(degreeRet);
	for (unsigned i = 0;i<=degreeRet;++i) {
		ret[i] = (*this)[i]+other[i];
	}
	return ret;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial& other) const {
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

template<typename T>
T& Polynomial<T>::operator[](int index) {
	return _coeffs[index];
}

template<typename T>
const T& Polynomial<T>::operator[](int index) const {
	return _coeffs[index];
}

template<typename T>
unsigned Polynomial<T>::degree() const {
	return _coeffs.size()-1;
}

template<typename T>
T Polynomial<T>::operator()(T x) const {
	T ret = 0;
	T potenz = 1;
	for (unsigned i = 0;i<=degree();++i) {
		ret += (*this)[i]*potenz;
		potenz *= x;
	}
	return ret;
}

template<typename T>
Polynomial<T> Polynomial<T>::shift(T p) {
	Polynomial ret(degree());
	for (unsigned i = 0;i<=degree();++i) {
		T potenz = 1;
		for (unsigned j = 0;j<=i;++j) {
			ret[i-j] += binomial(i, j)*potenz;
			potenz *= p;
		}
	}
	return ret;
}

template<typename T>
void printSigned(std::ostream& out, T d, bool printSign) {
	if (printSign and d>=0) {
		out << "+";
	}
	out << d;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& p) {
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
#endif
