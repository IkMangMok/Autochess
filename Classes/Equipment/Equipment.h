#pragma once

#define GUN 1
#define KNIFE 2

#include "cocos2d.h"
<<<<<<< HEAD
#include "Chess/Chess.h"
=======
>>>>>>> lx

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
<<<<<<< HEAD
	virtual void EquipToChess(Chess* Owner);
=======
	int getaddAttackDistance(){ return addAttackDistance; } //��������
	int getaddHealthLimit() { return addHealthLimit; };    //��������
	int getaddHealth() { return addHealth; };         //��ǰ����ֵ
	int getaddArmor() { return addArmor; };            //����
	float getaddAttackSpeed() { return addAttackSpeed; }; //����
	int getaddDamage() { return addDamage; };          //������
>>>>>>> lx
	int type;//װ������
private:
	//Chess* OwnerChess = NULL;
	float SearchDistance = 30;         //�ڵ�ͼ�ж�װ��Ŀ�������ľ��루could be better��

	friend class GameScene;
	friend class Package;
};

