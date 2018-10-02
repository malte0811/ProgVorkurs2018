#include <iostream>
#include <vector>

void printSorted(const std::vector<unsigned>& vec) {
	unsigned found = 0;
	unsigned lastMin = 0;
	unsigned currMin = 0;
	unsigned minCount;
	while (found<vec.size()) {
		minCount = 0;
		for (unsigned i = 0;i<vec.size();++i) {
			unsigned curr = vec[i];
			if (curr>lastMin) {
				if (curr<currMin or currMin == lastMin) {
					currMin = curr;
					minCount = 1;
				} else if (curr==currMin) {
					++minCount;
				}
			}
		}
		for (unsigned i = 0;i<minCount;++i) {
			std::cout << currMin << std::endl;
		}
		lastMin = currMin;
		found += minCount;
	}
}

int main() {
	std::vector<unsigned> vec = {1, 5, 2, 8, 1, 8, 6, 200, 4};
	printSorted(vec);
	return 0;
}
