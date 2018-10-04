#ifndef LINE_SWEEP_HPP
#define LINE_SWEEP_HPP
#include <vector>
#include "boxes.hpp"
struct SweepEvent {
	const Rect* rect;
	bool leftBorder;
	Coord getBorder() const;
};
bool operator<(const SweepEvent& a, const SweepEvent& b);

bool intersectsLineSweep(const std::vector<Rect>& boxes);

inline Coord SweepEvent::getBorder() const {
	if (leftBorder) {
		return (*rect)[x_min];
	} else {
		return (*rect)[x_max];
	}
}

inline bool operator<(const SweepEvent& a, const SweepEvent& b) {
	Coord borderA = a.getBorder();
	Coord borderB = b.getBorder();
	if (borderA<borderB) {
		return true;
	} else if (borderA>borderB) {
		return false;
	} else {
		return a.leftBorder&&!b.leftBorder;
	}
}
#endif
