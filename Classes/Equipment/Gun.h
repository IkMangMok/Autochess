#pragma once
#include "cocos2d.h"
#include "Equipment.h"

USING_NS_CC;

class Gun :public Equipment
{
public:
	CREATE_FUNC(Gun);
	static Gun* createGun();  //�����ϣ�Ӧ��ʹ�ú���ָ������

};

