#ifndef LINE_SWEEP_HPP
#define LINE_SWEEP_HPP
#include <vector>
#include "boxes.hpp"
struct SweepEvent {
	SweepEvent(unsigned rectId, bool leftBorder, Coord border): _rectId(rectId), _leftBorder(leftBorder),
		_border(border){}
	unsigned _rectId;
	bool _leftBorder;
	Coord _border;
	Coord getBorder() const;
};
bool operator<(const SweepEvent& a, const SweepEvent& b);

bool intersectsLineSweep(const std::vector<Rect>& boxes);

inline bool operator<(const SweepEvent& a, const SweepEvent& b) {
	if (a._border<b._border) {
		return true;
	} else if (a._border>b._border) {
		return false;
	} else {
		return a._leftBorder&&!b._leftBorder;
	}
}
#endif
