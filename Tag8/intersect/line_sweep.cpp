#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include "boxes.hpp"
#include "line_sweep.hpp"

bool intersectsLineSweep(const std::vector<Rect>& boxes) {
	std::cout << "Called" << std::endl;
	std::vector<SweepEvent> events;
	events.reserve(boxes.size()*2);
	for (unsigned i = 0;i<boxes.size();++i) {
		events.push_back(SweepEvent(i, true, boxes[i][x_min]));
		events.push_back(SweepEvent(i, false, boxes[i][x_max]));
	}
	std::cout << "Constructed events" << std::endl;
	std::sort(events.begin(), events.end());
	std::cout << "Sorted events" << std::endl;
	std::map<Coord, unsigned> boxesOnLine;
	for (SweepEvent& event:events) {
		const Rect& evRect = boxes[event._rectId];
		Coord yPos = evRect[y_min];
		if (event._leftBorder) {
			if (boxesOnLine.count(yPos)>0) {
				return true;
			}
			std::map<Coord, unsigned>::iterator it = boxesOnLine.insert({yPos, event._rectId}).first;
			if (it!=boxesOnLine.begin()) {
				--it;
				if (boxes[(*it).second][y_max]>=yPos) {
					return true;
				}
				++it;
			}
			++it;
			
			if (it!=boxesOnLine.end()) {
				if (boxes[(*it).second][y_min]<=evRect[y_max]) {
					return true;
				}
			}
		} else {
			boxesOnLine.erase(yPos);
		}
	}
	return false;
}
