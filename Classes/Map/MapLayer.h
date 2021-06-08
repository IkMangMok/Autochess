#include"cocos2d.h"

USING_NS_CC;

class MapLayer : public Layer {
public:
	static MapLayer* createMapLayer();
	virtual bool init();
	CREATE_FUNC(MapLayer);
};