#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"
#include "Data/GameData.h"
#include "Timer/RoundTimer.h"
#include"AudioEngine.h"
#include"ChessPile/ChessPile.h"
#include "cocos-ext.h"              //����cocos-ext.hͷ�ļ�
using namespace cocos2d::extension; //����cocos2d::extension�����ռ�

USING_NS_CC;

class scene1 : public AutoChess {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	scene1();
	~scene1();
	
private:
	RoundTimer* test_timer = RoundTimer::create(500);
	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);
	
	void update(float dt);
	CREATE_FUNC(scene1);
	
	//��ս������ƶ�����
	void ChessMoveInMouse();
	void SceneMouseBack(cocos2d::Ref* pSender);
	void onMouseScroll(Event* event);
	void onMouseMove(Event* event);
	void onMouseUp(Event* event);
	void onMouseDown(Event* event);
	int MouseToChess = -1;
	friend class Chess;

	void Win();  //�жϴ򶷽���

	//���������
	void PlayerBuyChess(cocos2d::Ref* pSender, Control::EventType controlEvent);
	ChessPile* Chesspile = ChessPile::create();
};