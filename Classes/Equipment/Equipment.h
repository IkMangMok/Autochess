#pragma once
#include "cocos2d.h"
#include "Chess/Chess1.h"

USING_NS_CC;

enum class EquipmentType
{
	None,
	Gun,          /* ǹ */
	Knife         /* �� */
	           
	//...
};
class Equipment :public Sprite
{
protected:


	float x_in_package = 0;       //����ս��ʱ��λ��
	float y_in_package = 0;

	bool equiped_or_not = 0;      //�Ƿ�װ��

	int type ;

public:
	virtual void EquipToChess(Chess* Owner) = 0;    //�����ӽ��мӳ�(a pure virtual func)

private:
	Chess* OwnerChess = NULL;
	float SearchDistance = 30;

	friend class scene1;
	friend class Package;
};

