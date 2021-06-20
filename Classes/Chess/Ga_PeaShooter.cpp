#include"Ga_PeaShooter.h"

Ga_PeaShooter::Ga_PeaShooter()       
{
	type = ga_peashooter;
	AttackDistance = 750;
	Health = 600;
	HealthLimit = Health;
	ManaOrigin = 0;
	Mana = ManaOrigin;
	ManaLimit = 100;
	Damage = 60;
	Armor = 20;
<<<<<<< HEAD
	AttackSpeed = 12.5f;
=======
	AttackSpeed = 1.5f;
>>>>>>> lx
	CoinsNeeded = 4;
	SoldCoins = 4;
	star = 1;
	picturename = "ga_peashooter%d.png";
	picturenum = 12;
	chessAnimation(picturename, picturenum,this, getPosition(), 0.08f, -1);
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
}
void Ga_PeaShooter::Skill()
{
	auto rate = (star == 1) ? 1.3f : (star == 2) ? 1.5f : 2.5f;
	if (OfPlayer == 0)
	{
		for (int i = 0; i < player1data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player1data.FightArray->arr[i]));
			if (temp->getPlayer() == OfPlayer && !temp->Die())
			{
				temp->setAttackSpeed(temp->getAttackSpeed() * rate * Magic);
<<<<<<< HEAD
				temp->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
=======
				temp->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / temp->getAttackSpeed());
>>>>>>> lx
				Mana = 0;
			}
		}
	}
	if (OfPlayer == 1)
	{
		for (int i = 0; i < player2data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player2data.FightArray->arr[i]));
			if (temp->getPlayer() == OfPlayer && !temp->Die())
			{
				temp->setAttackSpeed(temp->getAttackSpeed() * rate * Magic);
				temp->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
				Mana = 0;
			}
		}
	}
	TimeSet = 5.0f;
}
void Ga_PeaShooter::update(float dt)
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
		AttackTarget->setAttackSpeed(AttackTarget->getTempAttackSpeed());
		SkillFlag = 0;
	}
	else if (AttackTarget == (Chess*)nullptr)
	{
		SkillFlag = 0;
	}
	
}
Ga_PeaShooter* Ga_PeaShooter::createChess()
{
	auto Ga_PeaShooter = Ga_PeaShooter::create();
	
	Ga_PeaShooter->autorelease();
	return Ga_PeaShooter;
}

upgrade_Ga_PeaShooter::upgrade_Ga_PeaShooter()
{
	type = upgrade_ga_peashooter;
	AttackDistance = 750;
	Health = 900;
	HealthLimit = Health;
	ManaOrigin = 0;
	Mana = ManaOrigin;
	ManaLimit = 100;
	Damage = 90;
	Armor = 20;
<<<<<<< HEAD
	AttackSpeed = 12.5f;
=======
	AttackSpeed = 1.5f;
>>>>>>> lx
	CoinsNeeded = 0;
	SoldCoins = 11;
	star = 2;
}

upgrade_Ga_PeaShooter* upgrade_Ga_PeaShooter::createChess()
{
	auto Ga_PeaShooter = upgrade_Ga_PeaShooter::create();

	Ga_PeaShooter->autorelease();
	return Ga_PeaShooter;
}

_3star_Ga_PeaShooter::_3star_Ga_PeaShooter()
{
	type = _3star_ga_peashooter;
	AttackDistance = 750;
	Health = 1200;
	HealthLimit = Health;
	ManaOrigin = 0;
	Mana = ManaOrigin;
	ManaLimit = 100;
	Damage = 125;
	Armor = 20;
	AttackSpeed = 12.5f;
	CoinsNeeded = 0;
	SoldCoins = 35;
	star = 3;
}

_3star_Ga_PeaShooter* _3star_Ga_PeaShooter::createChess()
{
	auto Ga_PeaShooter = _3star_Ga_PeaShooter::create();

	

	Ga_PeaShooter->autorelease();
	return Ga_PeaShooter;
}