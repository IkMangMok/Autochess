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
	//void scene1::ObtainEquipment();//װ����ȡ
	bool package_shown = 0;
	//void scene1::ShowEquipment();  //����װ����ʾ

	void update(float dt);
	CREATE_FUNC(scene1);

	/*���湦�ܰ�ť�ص�����*/
	void SceneMouseBack(cocos2d::Ref* pSender);//�ص����˵���ť
	//��ս������ƶ����Ӽ�װ������
	void ChessMoveInMouse();

	void onMouseScroll(Event* event);//����������
	void onMouseMove(Event* event);
	void onMouseUp(Event* event);
	void onMouseDown(Event* event);

	bool EquipSearchChess(const float EquipX, const float EquipY,const int EquipIndex);//װ��������

	int MouseToChess = -1;
	int MouseSelectedEquip = -1;

	friend class Chess;

	void Win();  //�жϴ򶷽���
	//���������
	void PlayerBuyChess(cocos2d::Ref* pSender);


	/*--------------------��ս�ڼ�����ƶ�װ����غ���--------------------*/



};
