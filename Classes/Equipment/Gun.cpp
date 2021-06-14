#include "Gun.h"

Gun* Gun::createGun()
{
	auto gun = Gun::create();

	/*图像初始化*/
	gun->initWithFile("Gun.png");
	/*种类*/
	gun->type = GUN;

	/*属性加成设定值*/
	gun->addAttackDistance = 100; //攻击距离
	gun->addHealthLimit = 200;    //生命上限
	gun->addHealth = 200;         //当前生命值
	gun->addArmor = 0;            //护甲
	gun->addAttackSpeed = 0.3f; //攻速
	gun->addDamage = 50;          //攻击力

	gun->retain();
	return gun;
}