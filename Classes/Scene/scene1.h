#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"
#include"Chess/Chess1.h"
#include "Data/GameData.h"

#include "Data/PlayerData.h"
#include "Timer/RoundTimer.h"
#include"Chess/TestChess.h"
#include"AudioEngine.h"
#include "Equipment/Gun.h"
#include "Equipment/Knife.h"
#include "Equipment/Package.h"




class scene1 : public AutoChess {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();


private:
	RoundTimer* test_timer = RoundTimer::create(3);

	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);
	//void openPackage(cocos2d::Ref* pSender);


	Package* package = Package::createPackage();
	//void scene1::ObtainEquipment();//装备获取
	bool package_shown = 0;
	//void scene1::ShowEquipment();  //背包装备显示

	void update(float dt);
	CREATE_FUNC(scene1);

	/*界面功能按钮回调函数*/
	void SceneMouseBack(cocos2d::Ref* pSender);//回到主菜单按钮
	//备战期鼠标移动棋子及装备函数
	void ChessMoveInMouse();

	void onMouseScroll(Event* event);//鼠标滚动函数
	void onMouseMove(Event* event);
	void onMouseUp(Event* event);
	void onMouseDown(Event* event);

	bool EquipSearchChess(const float EquipX, const float EquipY,const int EquipIndex);//装备找棋子

	int MouseToChess = -1;
	int MouseSelectedEquip = -1;

	friend class Chess;

	void Win();  //判断打斗结束
	//玩家买棋子
	void PlayerBuyChess(cocos2d::Ref* pSender);


	/*--------------------备战期间鼠标移动装备相关函数--------------------*/



};
