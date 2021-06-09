#include"SunFlower.h"

SunFlower::SunFlower()        //初步设想：通过技能可以群体回血或获得金币/经验
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