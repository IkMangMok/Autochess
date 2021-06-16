#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Data/PlayerData.h"
#include"string"

USING_NS_CC;
using namespace std;

class HelpAndSetLayer :public Layer {
public:
	virtual bool init();
	static HelpAndSetLayer* createLayer();
	void BackToMenu(cocos2d::Ref* pSender);
	 //·µ»Ø°´Å¥
	CREATE_FUNC(HelpAndSetLayer);
};