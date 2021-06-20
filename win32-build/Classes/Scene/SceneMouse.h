#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"
#include"Chess/TestChess.h"
using namespace std;

class SceneMouse :public AutoChess {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	
private:
	
	CREATE_FUNC(SceneMouse);
	
};