#pragma once
#include"cocos2d.h"
#include"AutoChessScene.h"
#include"Player/Player.h"
#include"Chess/Chess1.h"

class scene1 : public AutoChess {
public:
	static cocos2d::Scene* createScene();//������
	virtual bool init();

private:
	void scene1::ChessMove(Chess* chess);
	void scene1Back(cocos2d::Ref* pSender);//�������˵�

	ccArray *pArray = ccArrayNew(1000);   //��¼���ӵ�����
	void update(float dt);
	CREATE_FUNC(scene1);
};