#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"
#include"Chess/Chess1.h"
<<<<<<< HEAD
#include "Data/GameData.h"
#include "Timer/RoundTimer.h"
#include"Chess/TestChess.h"
#include"AudioEngine.h"
=======

>>>>>>> lx
class scene1 : public AutoChess {
public:
	static cocos2d::Scene* createScene();//������
	virtual bool init();

private:
<<<<<<< HEAD
	RoundTimer* test_timer = RoundTimer::create(5);
	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);

=======
	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);//�������˵�

	ccArray *pArray = ccArrayNew(1000);   //��¼���ӵ�����
>>>>>>> lx
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
	void PlayerBuyChess(cocos2d::Ref* pSender);
};
