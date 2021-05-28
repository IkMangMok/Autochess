#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"
#include "Chess/Chess1.h"
#include "Data/GameData.h"
#include "Timer/RoundTimer.h"

extern GameData* global_data;

class scene1 : public AutoChess 
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

private:
	Sprite* ShopFrame = Sprite::create("ShopFrame.png");
	RoundTimer* test_timer = RoundTimer::create(5);
	Chess* person = Chess::createChess("test_chess_1.png", 112, 112);
	Chess* person1 = Chess::createChess("test_chess_2.png", 112, 176);

	void openShop();
	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);
	//ccArray *pArray = ccArrayNew(1000);   //记录棋子的数组
	void update(float dt);
	CREATE_FUNC(scene1);

	friend class Scene2;
};