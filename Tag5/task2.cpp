#include <iostream>
#include <vector>

void printSorted(const std::vector<unsigned>& vec) {
	unsigned numPrinted = 0;
	unsigned lastMin = 0;
	unsigned currMin = 0;
	while (numPrinted<vec.size()) {
		unsigned numFound = 0;
		for (unsigned i = 0;i<vec.size();++i) {
			if (vec[i]>lastMin) {
				if (vec[i]==currMin) {
					numFound++;
				} else if (vec[i]<currMin || currMin==lastMin) {
					currMin = vec[i];
					numFound = 1;
				}
			}
		}
		for (unsigned i = 0;i<numFound;++i) {
			std::cout << currMin << std::endl;
		}
		numPrinted += numFound;
		lastMin = currMin;
	}
}

int main() {
	std::vector<unsigned> vec = {1, 5, 1, 3, 78, 2, 6, 3};
	printSorted(vec);
	return 0;
}
