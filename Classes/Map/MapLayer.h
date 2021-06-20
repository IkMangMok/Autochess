#pragma once
#include"cocos2d.h"
USING_NS_CC;

class MapLayer : public Layer {
public:
	static MapLayer* createMapLayer();
	virtual bool init();
	void update(float dt);
	CREATE_FUNC(MapLayer);
};
struct IntMap {
	IntMap(int x1, int y1) { x = x1; y = y1; }
	IntMap() { x = 0; y = 0; };
	int x;
	int y;
};

IntMap MapIntReturn(Point point);
extern Point mapPosition[8][10];
extern bool ChessExist[8][10];