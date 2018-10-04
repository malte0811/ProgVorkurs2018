#ifndef COMPLEX_HPP
#define COMPLEX_HPP
class complex_double {
public:
	complex_double(): _re(0), _im(0) {}
	complex_double(double re): _re(re), _im(0) {}
	complex_double(double re, double im): _re(re), _im(im) {}
	double getRe() {
		return _re;
	}
	double getIm() {
		return _im;
	}
	void setRe(double re) {
		_re = re;
	}
private:
	double _re;
	double _im;
};

complex_double operator+(const complex_double& a, const complex_double b) {
	return complex_double(a.getRe()+b.getRe(), a.getIm()+b.getIm());
}
complex_double operator-(const complex_double& a, const complex_double b) {
	return complex_double(a.getRe()-b.getRe(), a.getIm()-b.getIm());
}
complex_double operator*(const complex_double& a, const complex_double b) {
	return complex_double(a.getRe()*b.getRe()-a.getIm()*b.getIm(),
							a.getIm()*b.getRe()+b.getIm()*a.getRe());
}
complex_double operator/(const complex_double& a, const complex_double b) {
	if (b==0) {
		throw "Teilen durch 0";
	}
	double factor = a.getRe()*b.getRe()+a.getIm()*b.getIm();
	return complex_double((a.getRe()*b.getRe()-a.getIm()*b.getIm())/factor,
							(a.getIm()*b.getRe()-b.getIm()*a.getRe()));
}

#endif
