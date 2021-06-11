#include"CherryBomb.h"

CherryBomb::CherryBomb()        //初步设想：通过技能可以群体回血或获得金币/经验
{
	AttackDistance = 375;
	Health = 700;
	HealthLimit = Health;
	Damage = 125;
	Armor = 10;
	AttackSpeed = 0.9f;
	CoinsNeeded = 3;
}

CherryBomb* CherryBomb::createChess()
{
	auto cherrybomb = CherryBomb::create();

	auto temp = Sprite::create("cherrybomb.png");
	cherrybomb->width = temp->getContentSize().width;
	cherrybomb->height = temp->getContentSize().height;
	cherrybomb->addChild(temp);
	cherrybomb->setPosition(cherrybomb->x, cherrybomb->y);
	cherrybomb->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / cherrybomb->AttackSpeed);
	cherrybomb->autorelease();
	return cherrybomb;
}