#include "Gun.h"

Gun* Gun::createGun()
{
	auto gun = Gun::create();

	/*ͼ���ʼ��*/
	gun->initWithFile("Gun.png");
	/*����*/
	gun->type = GUN;

	/*���Լӳ��趨ֵ*/
	gun->addAttackDistance = 100; //��������
	gun->addHealthLimit = 200;    //��������
	gun->addHealth = 200;         //��ǰ����ֵ
	gun->addArmor = 0;            //����
	gun->addAttackSpeed = 0.3f; //����
	gun->addDamage = 50;          //������

	gun->retain();
	return gun;
}