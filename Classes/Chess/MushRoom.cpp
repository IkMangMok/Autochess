#include"MushRoom.h"

MushRoom::MushRoom()
{
	type = mushroom;
	AttackDistance = 225;
	Health = 400;
	HealthLimit = Health;
	Damage = 100;
	Armor = 15;
	AttackSpeed = 1.1f;
	CoinsNeeded = 2;
}

MushRoom* MushRoom::createChess()
{
	auto mushroom = MushRoom::create();

	auto temp = Sprite::create("mushroom.png");
	mushroom->width = temp->getContentSize().width;
	mushroom->height = temp->getContentSize().height;
	mushroom->addChild(temp);
	mushroom->setPosition(mushroom->x, mushroom->y);
	mushroom->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / mushroom->AttackSpeed);
	mushroom->autorelease();
	return mushroom;
}