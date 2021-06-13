#include"WalNut.h"

WalNut::WalNut()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = walnut;
	AttackDistance = 80;
	Health = 1200;
	HealthLimit = Health;
	Damage = 30;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 1;
	star = 1;
}

WalNut* WalNut::createChess()
{
	auto walnut = WalNut::create();
	walnut->Blood->setBarChangeRate(Point(1, 0));
	walnut->Blood->setType(ProgressTimer::Type::BAR);
	walnut->Blood->setMidpoint(Point(0, 1));
	walnut->Blood->setScaleX(0.22);
	walnut->scheduleUpdate();
	walnut->addChild(walnut->Blood, 2);
	auto temp = Sprite::create("walnut.png");
	walnut->addChild(temp);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / walnut->AttackSpeed);
	walnut->autorelease();
	return walnut;
}

upgrade_WalNut::upgrade_WalNut()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = upgrade_walnut;
	AttackDistance = 80;
	Health = 2000;
	HealthLimit = Health;
	Damage = 50;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 3;
	star = 2;
}

upgrade_WalNut* upgrade_WalNut::createChess()
{
	auto walnut = upgrade_WalNut::create();
	walnut->Blood->setBarChangeRate(Point(1, 0));
	walnut->Blood->setType(ProgressTimer::Type::BAR);
	walnut->Blood->setMidpoint(Point(0, 1));
	walnut->Blood->setScaleX(0.22);
	walnut->scheduleUpdate();
	walnut->addChild(walnut->Blood, 2);
	auto temp = Sprite::create("upgrade_walnut.png");
	walnut->addChild(temp);
	walnut->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / walnut->AttackSpeed);
	walnut->autorelease();
	return walnut;
}