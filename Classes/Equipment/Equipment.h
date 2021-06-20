#pragma once

#define GUN 1
#define KNIFE 2

#include "cocos2d.h"
#include "Chess/Chess.h"

USING_NS_CC;

enum class EquipmentType
{
	None,
	Gun,
	Knife
};

class Equipment :public Sprite
{
protected:



	/*���Լӳ��趨ֵ*/
	int addAttackDistance; //��������
	int addHealthLimit;    //��������
	int addHealth;         //��ǰ����ֵ
	int addArmor;            //����
	float addAttackSpeed; //����
	int addDamage;          //������

public:
	/*�����ӽ���װ���ӳ�*/
	virtual void EquipToChess(Chess* Owner);
	int type;//װ������
private:
	//Chess* OwnerChess = NULL;
	float SearchDistance = 30;         //�ڵ�ͼ�ж�װ��Ŀ�������ľ��루could be better��

	friend class GameScene;
	friend class Package;
};

