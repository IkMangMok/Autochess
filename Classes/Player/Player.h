#ifndef NETWORKSMALLGAME_PLAYER_H
#define NETWORKSMALLGAME_PLAYER_H

#include "cocos2d.h"
#include "string"
<<<<<<< Updated upstream

class Player : public cocos2d::Sprite {
=======
#include "Scene/AutoChessScene.h"

using namespace cocos2d;
using namespace std;

class Player : public cocos2d::Sprite 
{
private:

	/*-----------�������-------------*/
	//����ϵͳ
	int Health = 100; //����ֵ
	//����ϵͳ
	int Level = 1; //��ҵȼ�
	int ExpValue = 0;   //����ֵ
	int BattleChessMaxNum = 1;  //������������
	//���ϵͳ
	int Money = 0;   //���
	ccArray* Equipment = ccArrayNew(100);   //װ����
	ccArray* PlayerChess = ccArrayNew(100);  //����


	/*------------������غ���-------------*/
	void ChangeHealth(int blood);
	void ChangeMoney(int benefit);
	void ChangeExp(int benefit);
	void BuyChess();//?�ݲ�����

public:
	CREATE_FUNC(Player);
	static Sprite* createPlayer();
	virtual bool init();

>>>>>>> Stashed changes

};
;
#endif