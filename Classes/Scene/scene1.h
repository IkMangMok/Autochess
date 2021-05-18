#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"

class scene1 : public AutoChess {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void scene1Back(cocos2d::Ref* pSender);
	CREATE_FUNC(scene1);
};