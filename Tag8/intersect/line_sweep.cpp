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
	for (const Rect& r:boxes) {
		events.push_back(SweepEvent{&r, true});
		events.push_back(SweepEvent{&r, false});
	}
	std::cout << "Constructed events" << std::endl;
	std::sort(events.begin(), events.end());
	std::cout << "Sorted events" << std::endl;
	std::map<Coord, const Rect*> boxesOnLine;
	for (SweepEvent& event:events) {
		Coord yPos = (*event.rect)[y_min];
		if (event.leftBorder) {
			if (boxesOnLine.count(yPos)>0) {
				return true;
			}
			std::map<Coord, const Rect*>::iterator it = boxesOnLine.insert({yPos, event.rect}).first;
			if (it!=boxesOnLine.begin()) {
				--it;
				if ((*(*it).second)[y_max]>=yPos) {
					return true;
				}
				++it;
			}
			++it;
			
			if (it!=boxesOnLine.end()) {
				if ((*(*it).second)[y_min]<=(*event.rect)[y_max]) {
					return true;
				}
			}
		} else {
			boxesOnLine.erase(yPos);
		}
	}
	return false;
}
