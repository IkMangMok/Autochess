#pragma once
#include "cocos2d.h"
#include "Equipment.h"

USING_NS_CC;
class Gun:public Equipment
{
protected:


public:

	/*������غ���*/
	CREATE_FUNC(Gun);
	static Gun* createGun();

	/*�����ӽ���װ���ӳ�*/
	//virtual void EquipToChess(Chess* Owner);
};

