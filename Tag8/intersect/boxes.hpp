#ifndef BOXES_HPP
#define BOXES_HPP
#include <array>

typedef int Coord;
enum BoundIndex {
	x_min,
	x_max,
	y_min,
	y_max
};

class Rect {
public:
	Rect(std::array<Coord, 4> bounds): _bounds(bounds) {}
	
	inline const Coord& operator[](int index) const {
		return _bounds[index];
	}
	
	inline bool intersects(const Rect& other) const {
		return other[x_min]<_bounds[x_max] && other[x_max]>_bounds[x_min] &&
				other[y_min]<_bounds[y_max] && other[y_max]>_bounds[y_min];
	}
	const std::array<Coord, 4> _bounds;
};

std::ostream& operator<<(std::ostream& out, const Rect& val);
#endif
