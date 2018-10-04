#ifndef PUNKT_HPP
#define PUNKT_HPP
#include <vector>

template<typename T>
class Punkt {
public:
	Punkt(unsigned dims): _data(dims, 0), _l1Norm(static_cast<T>(0)) {}
	Punkt(const std::vector<T>& data): _data(data), _l1Norm(0) {
		for (unsigned i = 0;i<data.size();++i) {
			_l1Norm += abs(data[i]);
		}
	}
	T getCoor(unsigned i) {
		if (i<0||i>=_data.size()) {
			throw "Ungültiger Index!";
		}
		return _data[i];
	}
	void setCoor(unsigned i, T val) {
		if (i<0||i>=_data.size()) {
			throw "Ungültiger Index!";
		}
		_l1Norm -= abs(_data[i]);
		_data[i] = val;
		_l1Norm += abs(val);
	}
	T getL1Norm() {
		return _l1Norm;
	}
private:
	static T abs(T val) {
		if (val>=static_cast<T>(0)) {
			return val;
		}
		return -val;
	}
	std::vector<T> _data;
	T _l1Norm;
};
#endif
