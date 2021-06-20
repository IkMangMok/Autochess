#include"TomatoBoom.h"

TomatoBoom::TomatoBoom()
{
	type = tomatoboom;
	AttackDistance = 75;
	Health = 1500;
	HealthLimit = Health;
	ManaOrigin = 0;
	Mana = ManaOrigin;
	ManaLimit = 120;
	Damage = 90;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 5;
	SoldCoins = 5;
	star = 1;
	picturename = "tomatoboom%d.png";
	picturenum = 7;
	chessAnimation(picturename, picturenum, this, getPosition(), 0.08f, -1);
	this->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / AttackSpeed);
}

TomatoBoom* TomatoBoom::createChess()
{
	auto TomatoBoom = TomatoBoom::create();

	TomatoBoom->autorelease();

	return TomatoBoom;
}
void TomatoBoom::Skill()
{
	auto Damaged = (star == 1) ? 250 : (star == 2) ? 450 : 9999;
	if (OfPlayer == 0)
	{
		for (int i = 0; i < player2data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player2data.FightArray->arr[i]));
			if (temp->getPlayer() != OfPlayer && !temp->Die())
			{
				temp->MagicHurt(Damaged * Magic);
				this->Hurted(Damaged * Magic * 0.1);
				Mana = 0;
			}
		}
	}
	if (OfPlayer == 1)
	{
		for (int i = 0; i < player1data.FightArray->num; i++)
		{
			auto temp = ((Chess*)(player1data.FightArray->arr[i]));
			if (temp->getPlayer() != OfPlayer && !temp->Die())
			{
				temp->MagicHurt(Damaged * Magic);
				this->Hurted(Damaged * Magic * 0.1);
				Mana = 0;
			}
		}
	}
}

upgrade_TomatoBoom::upgrade_TomatoBoom()
{
	type = upgrade_tomatoboom;
	AttackDistance = 75;
	Health = 2000;
	HealthLimit = Health;
	ManaOrigin = 0;
	Mana = ManaOrigin;
	ManaLimit = 120;
	Damage = 120;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 14;
	star = 2;
}

upgrade_TomatoBoom* upgrade_TomatoBoom::createChess()
{
	auto TomatoBoom = upgrade_TomatoBoom::create();

	TomatoBoom->autorelease();
	return TomatoBoom;
}

_3star_TomatoBoom::_3star_TomatoBoom()
{
	type = _3star_tomatoboom;
	AttackDistance = 75;
	Health = 2800;
	HealthLimit = Health;
	ManaOrigin = 0;
	Mana = ManaOrigin;
	ManaLimit = 120;
	Damage = 150;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 0;
	SoldCoins = 44;
	star = 3;
}

_3star_TomatoBoom* _3star_TomatoBoom::createChess()
{
	auto TomatoBoom = _3star_TomatoBoom::create();

	TomatoBoom->autorelease();
	return TomatoBoom;
}