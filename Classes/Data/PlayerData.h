#pragma once
#include"cocos2d.h"
#include"GameData.h"
USING_NS_CC;


class PlayerData {
private:
	int LifeLimit = 100;   //����ֵ����
	int HealthValue = LifeLimit; //����ֵ
	int Grade = 1; //��ҵȼ�
	int ExperienceValue = 0;   //����ֵ
	int Gold = 5;  //���
	ccArray* equipment = ccArrayNew(100);   //װ��
	ccArray* PlayerArray = ccArrayNew(100);   //��ұ�ս������������
	bool HaveNewChess = 0;
public:
	void Hurted(int blood){ HealthValue -= blood;}
	void BuyChess();
	int chessnumber[ChessNumber];
	//CREATE_FUNC(PlayerData);
	friend class GameSprite;
	friend class ChessPile;
	friend class GameScene;
};

extern PlayerData player1data;
extern PlayerData player2data;