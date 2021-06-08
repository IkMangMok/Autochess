#pragma once
#include "cocos2d.h"
#include "Equipment.h"

USING_NS_CC;

class Knife :public Equipment
{
protected:
	int addAttackDistance = 5;  //��������
	int addHealthLimit = 0;     //��������
	int addHealth = 0;          //����ֵ
	int addArmor = 0;        //����
	float addAttackSpeed = 0.1f;  //�����ٶ�
	int addDamage = 10;     //������
public:
	CREATE_FUNC(Knife);
	static Knife* createKnife();

	virtual void EquipToChess(Chess* owner);    //�ӳɣ�װ����
	//virtual void RemoveFrom(Chess* owner);  //ȡ���ӳɣ�жװʱ�ã�

private:

};