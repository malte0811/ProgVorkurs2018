#include "gerade.hpp"

bool istGerade(unsigned n) {
	if (n==0) {
		return true;
	}
	return istUngerade(n-1);
}
