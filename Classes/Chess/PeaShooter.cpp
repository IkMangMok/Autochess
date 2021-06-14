#include"PeaShooter.h"
#include"cocos2d.h"
#include"AppDelegate.h"
using namespace cocos2d;
USING_NS_CC;

PeaShooter::PeaShooter()
{
	type = pealauncher;
	AttackDistance = 450;
	Health = 600;
	HealthLimit = Health;
	Damage = 100;
	Armor = 10;
	AttackSpeed = 1.0f;
	CoinsNeeded = 2;
	SoldCoins = 2;
	star = 1;
};
PeaShooter* PeaShooter::createChess()
{

	auto peaShooter = PeaShooter::create();
	peaShooter->Blood->setBarChangeRate(Point(1, 0));
	peaShooter->Blood->setType(ProgressTimer::Type::BAR);
	peaShooter->Blood->setMidpoint(Point(0, 1));
	peaShooter->Blood->setScaleX(0.22);
	peaShooter->scheduleUpdate();
	peaShooter->addChild(peaShooter->Blood, 2);
	auto temp = Sprite::create("pealauncher.png");
	peaShooter->addChild(temp);
	peaShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / peaShooter->AttackSpeed);
	peaShooter->autorelease();
	return peaShooter;

}

upgrade_PeaShooter::upgrade_PeaShooter()
{
	type = pealauncher;
	AttackDistance = 450;
	Health = 900;
	HealthLimit = Health;
	Damage = 150;
	Armor = 10;
	AttackSpeed = 1.0f;
	CoinsNeeded = 0;
	SoldCoins = 6;
	star = 1;
};
upgrade_PeaShooter* upgrade_PeaShooter::createChess()
{

	auto peaShooter = upgrade_PeaShooter::create();
	peaShooter->Blood->setBarChangeRate(Point(1, 0));
	peaShooter->Blood->setType(ProgressTimer::Type::BAR);
	peaShooter->Blood->setMidpoint(Point(0, 1));
	peaShooter->Blood->setScaleX(0.22);
	peaShooter->scheduleUpdate();
	peaShooter->addChild(peaShooter->Blood, 2);
	auto temp = Sprite::create("upgrade_pealauncher.png");
	peaShooter->addChild(temp);
	peaShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / peaShooter->AttackSpeed);
	peaShooter->autorelease();
	return peaShooter;

}