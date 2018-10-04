#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "line_sweep.hpp"
#include "boxes.hpp"
#include "quad_tree.hpp"

int main(int argc, char** argv) {
	std::vector<Rect> boxes;
	std::ifstream in(argv[1]);
	std::string line;
	while (std::getline(in, line)) {
		std::stringstream lstream(line);
		std::array<int, 4> rect;
		lstream >> rect[x_min] >> rect[x_max] >> rect[y_min] >> rect[y_max];
		if (!lstream) {
			std::cout << "ERROR" << std::endl;
			return 1;
		}
		boxes.push_back(rect);
	}
	bool intersect = intersectsLineSweep(boxes);//intersectsQuadTree(boxes);//
	std::cout << intersect << std::endl;
	return 0;
}
