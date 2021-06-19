#include"WalNut.h"

WalNut::WalNut()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = walnut;
	AttackDistance = 100;
	Health = 800;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 90;
	Damage = 38;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 1;
	star = 1;
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
	
}
void WalNut::Skill()
{
	TimeSet = 5.0f;
	HurtRate = 0.9 - (0.1 * star);
	Mana = 0;
}
void WalNut::update(float dt)
{
	
	if (Mana == ManaLimit)           //释放技能
	{
		Skill();
		SkillFlag = 1;
	}
	if (SkillFlag)
	{
		TimeSet -= dt;
	}
	if (fabs(TimeSet) < 1e-1 && SkillFlag)
	{
		HurtRate = 1.0f;
		SkillFlag = 0;
	}
}
WalNut* WalNut::createChess()
{
	auto walnut = WalNut::create();
	walnut->picturename = "nut%d.png";
	walnut->chessAnimation(walnut->picturename, 15, walnut, walnut->getPosition(), 0.08f, -1);
	walnut->autorelease();
	return walnut;
}

upgrade_WalNut::upgrade_WalNut()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = upgrade_walnut;
	AttackDistance = 100;
	Health = 1500;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 90;
	Damage = 60;
	Armor = 50;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 3;
	star = 2;
}

upgrade_WalNut* upgrade_WalNut::createChess()
{
	auto walnut = upgrade_WalNut::create();
	walnut->picturename = "upgrade_nut%d.png";
	walnut->picturenum = 13;
	walnut->chessAnimation(walnut->picturename, walnut->picturenum, walnut, walnut->getPosition(), 0.08f, -1);
	walnut->autorelease();
	return walnut;
}

_3star_WalNut::_3star_WalNut()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	type = _3star_walnut;
	AttackDistance = 100;
	Health = 2300;
	HealthLimit = Health;
	Mana = 0;
	ManaLimit = 90;
	Damage = 90;
	Armor = 70;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 9;
	star = 3;
}

_3star_WalNut* _3star_WalNut::createChess()
{
	auto walnut = _3star_WalNut::create();

	walnut->picturename = "upgrade_nut%d.png";
	walnut->picturenum = 13;
	walnut->chessAnimation(walnut->picturename, walnut->picturenum, walnut, walnut->getPosition(), 0.08f, -1);
	walnut->autorelease();
	return walnut;
}