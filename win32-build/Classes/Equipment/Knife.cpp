#include "Knife.h"

Knife* Knife::createKnife()
{
	auto knife = Knife::create();

	/*图像初始化*/
	knife->initWithFile("Knife.png");
	/*种类*/
	knife->type = KNIFE;

	/*属性加成设定值*/
	knife->addAttackDistance = 100; //攻击距离
	knife->addHealthLimit = 200;    //生命上限
	knife->addHealth = 200;         //当前生命值
	knife->addArmor = 0;            //护甲
	knife->addAttackSpeed = 0.3f; //攻速
	knife->addDamage = 50;          //攻击力

	knife->retain();
	return knife;
}