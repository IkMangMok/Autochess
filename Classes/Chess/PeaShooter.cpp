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
	ManaLimit = 40;
	ManaOrigin = 0;
	Mana = 0;
	Damage = 100;
	Armor = 10;
	AttackSpeed = 1.0f;
	CoinsNeeded = 2;
	SoldCoins = 2;
	star = 1;
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
};
PeaShooter* PeaShooter::createChess()
{

	auto peaShooter = PeaShooter::create();

	peaShooter->picturename = "Bean%d.png";
	peaShooter->picturenum = 12;
	peaShooter->chessAnimation(peaShooter->picturename, peaShooter->picturenum, peaShooter, peaShooter->getPosition(), 0.08f, -1);
	
	peaShooter->autorelease();
	return peaShooter;

}
void PeaShooter::Skill()
{
	TimeSet = 3.0f;

	AttackSpeed = AttackSpeed * (1.25 + 0.25 * star);
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
	Mana = 0;
}
void PeaShooter::update(float dt)
{
	if (fabs(Mana - ManaLimit) < 1e-6 && AttackTarget != (Chess*)nullptr)           //ÊÍ·Å¼¼ÄÜ
	{
		Skill();
		SkillFlag = 1;
	}
	if (SkillFlag)
	{
		TimeSet -= dt;
	}
	if (fabs(TimeSet) < 1e-1 && SkillFlag && AttackTarget != (Chess*)nullptr)
	{
		AttackSpeed = AttackSpeed / (1.25 + 0.25 * star);
		this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
		SkillFlag = 0;
	}
}
upgrade_PeaShooter::upgrade_PeaShooter()
{
	type = upgrade_pealauncher;
	AttackDistance = 450;
	Health = 900;
	HealthLimit = Health;
	Damage = 150;
	ManaLimit = 40;
	ManaOrigin = 0;
	Mana = 0;
	Armor = 10;
	AttackSpeed = 1.0f;
	CoinsNeeded = 0;
	SoldCoins = 5;
	star = 2;
};
upgrade_PeaShooter* upgrade_PeaShooter::createChess()
{

	auto peaShooter = upgrade_PeaShooter::create();

	peaShooter->picturename = "Bean%d.png";
	peaShooter->picturenum = 12;
	peaShooter->chessAnimation(peaShooter->picturename, peaShooter->picturenum, peaShooter, peaShooter->getPosition(), 0.08f, -1);
	
	peaShooter->autorelease();
	return peaShooter;

}

_3star_PeaShooter::_3star_PeaShooter()
{
	type = _3star_pealauncher;
	AttackDistance = 450;
	Health = 1300;
	HealthLimit = Health;
	Damage = 190;
	ManaLimit = 40;
	ManaOrigin = 0;
	Mana = 0;
	Armor = 10;
	AttackSpeed = 1.0f;
	CoinsNeeded = 0;
	SoldCoins = 17;
	star = 3;
};
_3star_PeaShooter* _3star_PeaShooter::createChess()
{

	auto peaShooter = _3star_PeaShooter::create();

	peaShooter->picturename = "upgrade_bean%d.png";
	peaShooter->picturenum = 15;
	peaShooter->chessAnimation(peaShooter->picturename, peaShooter->picturenum, peaShooter, peaShooter->getPosition(), 0.08f, -1);

	peaShooter->autorelease();
	return peaShooter;

}