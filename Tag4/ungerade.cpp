#include "ungerade.hpp"
bool istUngerade(unsigned n) {
	if (n==1) {
		return true;
	}
	return istGerade(n-1);
}
