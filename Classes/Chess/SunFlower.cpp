#include"SunFlower.h"

SunFlower::SunFlower()        //�������룺ͨ�����ܿ���Ⱥ���Ѫ���ý��/����
{
	AttackDistance = 750;
	Health = 300;
	HealthLimit = Health;
	Damage = 50;
	Armor = 5;
	AttackSpeed = 0.8f;
	CoinsNeeded = 1;
}

SunFlower* SunFlower::createChess()
{
	auto sunflower = SunFlower::create();

	auto temp = Sprite::create("sunflower.png");
	sunflower->addChild(temp);
	sunflower->setPosition(sunflower->x, sunflower->y);
	sunflower->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / sunflower->AttackSpeed);
	sunflower->autorelease();
	return sunflower;
}