#pragma once
#include"cocos2d.h"

USING_NS_CC;

class mapPosition {
public:
	int x_in_map;
	int y_in_map;
	float x_in_origin;
	float y_in_origin;
	mapPosition(int x, int y);
	mapPosition(Point point);
	void map_to_origin();
	void origin_to_map();
	bool out_of_map();
	Point getMapPosition() { return Point(x_in_origin, y_in_origin); }
};
