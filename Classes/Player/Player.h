#pragma once
#include "cocos2d.h"
#include "string"
#include"Scene/AutoChessScene.h"

using namespace cocos2d;
using namespace std;

class Player : public cocos2d::Sprite {
private:
	int LifeLimit = 0;   //����ֵ����
	int HealthValue = LifeLimit; //����ֵ
	int Grade; //��ҵȼ�
	int ExperienceValue;   //����ֵ
	int Gold;   //���
	ccArray* equipment = ccArrayNew(100);   //װ����
	ccArray* PlayerChess = ccArrayNew(100);  //����

public:
	void Hurted(int blood); //�ܵ��˺�
	void BuyChess();

};

