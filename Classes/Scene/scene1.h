#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"
#include"Chess/Chess1.h"

class scene1 : public AutoChess {
public:
	static cocos2d::Scene* createScene();//主界面
	virtual bool init();

private:
	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);//返回主菜单

	ccArray *pArray = ccArrayNew(1000);   //记录棋子的数组
	void update(float dt);
	CREATE_FUNC(scene1);
};