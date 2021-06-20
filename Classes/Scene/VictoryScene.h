#pragma once
#include "cocos2d.h"

USING_NS_CC;

class VictoryScene:public Scene
{
public:
	static Scene* createVictoryScene();
	CREATE_FUNC(VictoryScene);
private:
	virtual bool init();
	void backToMenu(cocos2d::Ref* pSender);


};

