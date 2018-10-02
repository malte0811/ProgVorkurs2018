#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include <vector>
#include <ostream>
#include <initializer_list>
class Polynomial {
public:
	explicit Polynomial(unsigned degree);
	explicit Polynomial(std::initializer_list<double> coeffs);
	Polynomial(double);
	Polynomial operator+(const Polynomial& other) const;
	Polynomial operator*(const Polynomial& other) const;
	double operator()(double x) const;
	double& operator[](int index);
	const double& operator[](int index) const;
	unsigned degree() const;
	Polynomial shift(double x);
	double limitAtInfinity(bool positiveInf);
private:
	std::vector<double> _coeffs;
};
std::ostream& operator<<(std::ostream& out, const Polynomial& p);

#endif
