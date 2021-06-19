#include"CabbagePult.h"

CabbagePult::CabbagePult()       
{
	type = cabbagepult;
	AttackDistance = 225;
	Health = 600;
	HealthLimit = Health;
	ManaOrigin = 60;
	Mana = ManaOrigin;
	ManaLimit = 120;
	Damage = 90;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 5;
	SoldCoins = 5;
	star = 1;
}

CabbagePult* CabbagePult::createChess()
{
	auto CabbagePult = CabbagePult::create();

	auto temp = Sprite::create("cabbagepult.png");
	CabbagePult->addChild(temp);
	CabbagePult->autorelease();
	
	return CabbagePult;
}
void CabbagePult::Skill()
{
	TimeSet = 0.5f + 0.5 * star;
	
	AttackTarget->unschedule(CC_SCHEDULE_SELECTOR(Chess::Attack));   //单体眩晕
	AttackTarget->unscheduleUpdate();
	AttackTarget->setSpeed(0);
	AttackTarget->AttackTarget = (Chess*)nullptr;
	Mana = 0;
	
}
void CabbagePult::update(float dt)
{
	if (fabs(Mana - ManaLimit) < 1e-6 && AttackTarget != (Chess*)nullptr)           //释放技能
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
		AttackTarget->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1.0f / AttackTarget->getAttackSpeed());
		AttackTarget->scheduleUpdate();
		AttackTarget->setSpeed(AttackTarget->getTempSpeed());  
																
		
		SkillFlag = 0;
	}
}
upgrade_CabbagePult::upgrade_CabbagePult()
{
	type = upgrade_cabbagepult;
	AttackDistance = 225;
	Health = 800;
	HealthLimit = Health;
	ManaOrigin = 60;
	Mana = ManaOrigin;
	ManaLimit = 120;
	Damage = 120;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 14;
	star = 2;
}

upgrade_CabbagePult* upgrade_CabbagePult::createChess()
{
	auto CabbagePult = upgrade_CabbagePult::create();

	auto temp = Sprite::create("upgrade_cabbagepult.png");

	CabbagePult->addChild(temp);
	
	CabbagePult->autorelease();
	return CabbagePult;
}

_3star_CabbagePult::_3star_CabbagePult()
{
	type = _3star_cabbagepult;
	AttackDistance = 225;
	Health = 1200;
	HealthLimit = Health;
	ManaOrigin = 60;
	Mana = ManaOrigin;
	ManaLimit = 120;
	Damage = 150;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 44;
	star = 3;
}

_3star_CabbagePult* _3star_CabbagePult::createChess()
{
	auto CabbagePult = _3star_CabbagePult::create();

	auto temp = Sprite::create("upgrade_cabbagepult.png");

	CabbagePult->addChild(temp);

	CabbagePult->autorelease();
	return CabbagePult;
}