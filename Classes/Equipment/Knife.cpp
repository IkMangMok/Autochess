#include "Knife.h"

Knife* Knife::createKnife()
{
	auto knife = Knife::create();

	/*ͼ���ʼ��*/
	knife->initWithFile("Knife.png");
	/*����*/
	knife->type = KNIFE;

	/*���Լӳ��趨ֵ*/
	knife->addAttackDistance = 100; //��������
	knife->addHealthLimit = 200;    //��������
	knife->addHealth = 200;         //��ǰ����ֵ
	knife->addArmor = 0;            //����
	knife->addAttackSpeed = 0.3f; //����
	knife->addDamage = 50;          //������

	knife->retain();
	return knife;
}