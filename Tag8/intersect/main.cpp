#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include "line_sweep.hpp"
#include "boxes.hpp"
#include "quad_tree.hpp"

int main(int argc, char** argv) {
	if (argc<2) {
		std::cout << "Missing instance name" << std::endl;
		return 1;
	}
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
	std::cout << "Line sweep..." << std::endl;
	clock_t start = clock();
	bool intersect = intersectsLineSweep(boxes);//intersectsQuadTree(boxes);//
	clock_t end = clock();
	std::cout << "Found intersections: " << intersect << std::endl;
	std::cout << "Took " <<  static_cast<double>(end-start)/ CLOCKS_PER_SEC << " seconds" << std::endl;
	
	std::cout << "Quad tree..." << std::endl;
	start = clock();
	intersect = intersectsQuadTree(boxes);
	end = clock();
	std::cout << "Found intersections: " << intersect << std::endl;
	std::cout << "Took " <<  static_cast<double>(end-start)/ CLOCKS_PER_SEC << " seconds" << std::endl;
	return 0;
}
