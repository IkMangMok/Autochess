#include"SunFlower.h"

SunFlower::SunFlower()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = sunflower;
	AttackDistance = 750;
	Health = 300;
	HealthLimit = Health;
	Damage = 50;
	Armor = 5;
	AttackSpeed = 0.8f;
	CoinsNeeded = 1;
	SoldCoins = 1;
	star = 1;
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

upgrade_SunFlower::upgrade_SunFlower()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = upgrade_sunflower;
	AttackDistance = 750;
	Health = 500;
	HealthLimit = Health;
	Damage = 80;
	Armor = 5;
	AttackSpeed = 0.8f;
	CoinsNeeded = 0;
	SoldCoins = 3;
	star = 2;
}

upgrade_SunFlower* upgrade_SunFlower::createChess()
{
	auto sunflower = upgrade_SunFlower::create();

	auto temp = Sprite::create("upgrade_sunflower.png");
	sunflower->addChild(temp);
	sunflower->setPosition(sunflower->x, sunflower->y);
	sunflower->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / sunflower->AttackSpeed);
	sunflower->autorelease();
	return sunflower;
}