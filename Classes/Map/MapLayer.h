#include"cocos2d.h"

USING_NS_CC;

class MapLayer : public Layer {
public:
	static MapLayer* createMapLayer();
	virtual bool init();
	CREATE_FUNC(MapLayer);
};
struct IntMap {
	IntMap(int x1, int y1) { x = x1; y = y1; }
	int x;
	int y;
};

struct _map {
	float x;
	float y;
};

extern _map mapPosition[8][10];
extern bool ChessExist[8][10];