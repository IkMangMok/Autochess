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
	cocos2d::LayerColor* s_layer;
	virtual bool init();

private:
	RoundTimer* test_timer = RoundTimer::create(5);

	chessInfo Used[4];
	int i1=0,i2=1,i3=2,i4=3;
	int x=470;
	//实在不知道怎么传参 自闭中

	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);

	void chessStore(cocos2d::Ref* pSender);
	void openChessStore();
	void closeChessStore();
	void storeChess(int i);
	void closeLayer(cocos2d::Ref* pSender);
	void buy1(cocos2d::Ref* pSender);
	void buy2(cocos2d::Ref* pSender);
	void buy3(cocos2d::Ref* pSender);
	void buy4(cocos2d::Ref* pSender);


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
