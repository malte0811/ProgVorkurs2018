#ifndef PUNKT_HPP
#define PUNKT_HPP
#include <vector>
#include <initializer_list>

template<typename T>
class Punkt {
public:
	Punkt(unsigned dim);
	Punkt(std::initializer_list<T> list);
	unsigned getDimension() const;
	T getL1Norm() const;
	class Reference {
	public:
		operator T() const;
		Reference operator=(const T&);
	private:
		Reference(Punkt<T>& owner, unsigned index): _owner(owner), _index(index) {}
		Punkt<T>& _owner;
		unsigned _index;
		friend Punkt<T>;
	};
	Reference operator[](unsigned index);
private:
	static T abs(const T&);
	std::vector<T> _data;
	T _cachedL1 = 0;
	friend Reference;
};

template<typename T>
Punkt<T>::Punkt(unsigned dim): _data(dim, 0) {}

template<typename T>
Punkt<T>::Punkt(std::initializer_list<T> data): _data(data) {
	for (unsigned i = 0;i<_data.size();++i) {
		_cachedL1 += abs(_data[i]);
	}
}

template<typename T>
T Punkt<T>::abs(const T& in) {
	if (in>static_cast<T>(0)) {
		return in;
	} else {
		return -in;
	}
}

template<typename T>
unsigned Punkt<T>::getDimension() const {
	return _data.size();
}

template<typename T>
T Punkt<T>::getL1Norm() const {
	return _cachedL1;
}

template<typename T>
typename Punkt<T>::Reference Punkt<T>::operator[](unsigned index) {
	return Reference(*this, index);
}

template<typename T>
Punkt<T>::Reference::operator T() const {
	return _owner._data[_index];
}

template<typename T>
typename Punkt<T>::Reference Punkt<T>::Reference::operator=(const T& newVal) {
	T oldVal = _owner._data[_index];
	T oldAbs = abs(oldVal);
	T newAbs = abs(newVal);
	_owner._data[_index] = newVal;
	// Verhindert eventuelle Überläufe
	_owner._cachedL1 -= oldAbs;
	_owner._cachedL1 += newAbs;
	return *this;
}
#endif
