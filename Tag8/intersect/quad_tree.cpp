#include "quad_tree.hpp"
#include "boxes.hpp"
#include <iostream>

bool intersectsQuadTree(const std::vector<Rect>& boxes) {
	std::array<int, 4> outerBounds{0, 0, 0, 0};
	bool first = true;
	for (const Rect& rect:boxes) {
		if (first) {
			outerBounds = rect._bounds;
			first = false;
		} else {
			if (rect[x_min]<outerBounds[x_min]) {
				outerBounds[x_min] = rect[x_min];
			}
			if (rect[y_min]<outerBounds[y_min]) {
				outerBounds[y_min] = rect[y_min];
			}
			if (rect[x_max]>outerBounds[x_max]) {
				outerBounds[x_max] = rect[x_max];
			}
			if (rect[y_max]>outerBounds[y_max]) {
				outerBounds[y_max] = rect[y_max];
			}
		}
	}
	int sizeX = outerBounds[x_max]-outerBounds[x_min];
	int sizeY = outerBounds[y_max]-outerBounds[y_min];
	int maxSize;
	if (sizeX>sizeY) {
		maxSize = sizeX;
	} else {
		maxSize = sizeY;
	}
	int power = 0;
	++maxSize;
	while (maxSize>0) {
		maxSize /= 2;
		++power;
	}
	std::cout << power << std::endl;
	QuadTree t(outerBounds[x_min], outerBounds[y_min], power);
	for (const Rect& r:boxes) {
		const Rect* intersect = t.insertAndIntersect(r);
		if (intersect!=nullptr) {
			std::cout << *intersect << " intersects with " << r << std::endl;
			return true;
		}
	}
	std::cout << "No intersections!" << std::endl;
	return false;
}

const Rect* findIntersecting(const std::vector<Rect>& rects, const Rect& r) {
	for (const Rect& old:rects) {
		if (old.intersects(r)) {
			return &old;
		}
	}
	return nullptr;
}

const Rect* QuadTree::insertAndIntersect(const Rect& r) {
	if (isLeaf()) {
		if (_containedRects.size()<100) {
			const Rect* intersect = findIntersecting(_containedRects, r);
			_containedRects.push_back(r);
			return intersect;
		}
		bool canSplit = _bounds[x_max]>_bounds[x_min]+1;
		if (!canSplit) {
			return &_containedRects[0];
		}
		int offset = 1<<(_power-1);
		for (unsigned i = 0;i<4;++i) {
			int xMin = _bounds[x_min]+(i&1)*offset;
			int yMin = _bounds[y_min]+(i&2)/2*offset;
			_subTrees[i] = std::make_unique<QuadTree>(xMin, yMin, _power-1);
			for (Rect& old:_containedRects) {
				if (_subTrees[i]->contains(old)) {
					//These didn't intersect before, so we don't need to check that
					_subTrees[i]->insertAndIntersect(old);
				}
			}
		}
	}

	_containedRects.push_back(r);
	for (unsigned i = 0;i<4;++i) {
		if (_subTrees[i]->contains(r)) {
			const Rect* intersect = _subTrees[i]->insertAndIntersect(r);
			if (intersect!=nullptr)
				return intersect;
		}
	}
	return nullptr;
}

bool QuadTree::isLeaf() const {
	return _subTrees[bottom_left]==nullptr;
}

bool QuadTree::contains(const Rect& r) const {
	return _bounds.intersects(r);
}

std::ostream& operator<<(std::ostream& out, const Rect& val) {
	out << "[" << val[x_min] << ", " << val[x_max] << "]x[" << val[y_min] << ", " << val[y_max] << "]";
	return out;
}
