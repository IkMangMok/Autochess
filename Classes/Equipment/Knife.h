#pragma once
#include "cocos2d.h"
#include "Equipment.h"
USING_NS_CC;
class Knife:public Equipment
{
protected:


public:

	/*������غ���*/
	CREATE_FUNC(Knife);
	static Knife* createKnife();

	/*�����ӽ���װ���ӳ�*/
	//virtual void EquipToChess(Chess* Owner);
};

