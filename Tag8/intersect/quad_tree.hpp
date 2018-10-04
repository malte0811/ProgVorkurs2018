#ifndef QUAD_TREE_HPP
#define QUAD_TREE_HPP
#include <vector>
#include <array>
#include <memory>
#include <ostream>
#include "boxes.hpp"

enum SubtreeIndex {
	bottom_left,
	bottom_right,
	top_left,
	top_right
};

class QuadTree {
public:
	QuadTree(int xMin, int yMin, int power): _bounds({xMin, xMin+(1<<power), yMin, yMin+(1<<power)}), _power(power) {}
	const Rect* insertAndIntersect(const Rect& r);
	bool isLeaf() const;
	bool contains(const Rect& r) const;
private:
	std::unique_ptr<QuadTree> _subTrees[4] = {nullptr, nullptr, nullptr, nullptr};
	std::vector<Rect> _containedRects;
	const Rect _bounds;
	const int _power;
};

bool intersectsQuadTree(const std::vector<Rect>& boxes);
#endif
