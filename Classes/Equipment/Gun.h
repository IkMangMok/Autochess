#pragma once
#include "cocos2d.h"
#include "Equipment.h"

USING_NS_CC;

class Gun :public Equipment
{
protected:
	int addAttackDistance = 20;  //��������
	int addHealthLimit = 0;     //��������
	int addHealth = 0;          //����ֵ
	int addArmor = 0;        //����
	float addAttackSpeed = 0.1f;  //�����ٶ�
	int addDamage = 5;     //������
public:
	CREATE_FUNC(Gun);
	static Gun* createGun();

	virtual void EquipToChess(Chess* owner);    //�ӳɣ�װ����


private:

};