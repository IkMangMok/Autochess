#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"
#include"Chess/Chess1.h"
#include "Data/GameData.h"
#include "Timer/RoundTimer.h"
#include"Chess/TestChess.h"
#include"AudioEngine.h"
class scene1 : public AutoChess {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

private:
	RoundTimer* test_timer = RoundTimer::create(5);
	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);

	void chessStore();
	void update(float dt);
	CREATE_FUNC(scene1);
	
	//备战期鼠标移动函数
	void ChessMoveInMouse();
	void SceneMouseBack(cocos2d::Ref* pSender);
	void onMouseScroll(Event* event);
	void onMouseMove(Event* event);
	void onMouseUp(Event* event);
	void onMouseDown(Event* event);
	int MouseToChess = -1;
	friend class Chess;

	void Win();  //判断打斗结束

	//玩家买棋子
	void PlayerBuyChess(cocos2d::Ref* pSender);
};
