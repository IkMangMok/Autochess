#include"CornShooter.h"

CornShooter::CornShooter()       
{
	type = cornshooter;
	AttackDistance = 225;
	Health = 600;
	HealthLimit = Health;
	Damage = 90;
	Armor = 20;
	AttackSpeed = 0.5f;
	CoinsNeeded = 2;
}

CornShooter* CornShooter::createChess()
{
	auto CornShooter = CornShooter::create();

	auto temp = Sprite::create("cornshooter.png");
	CornShooter->width = temp->getContentSize().width;
	CornShooter->height = temp->getContentSize().height;
	CornShooter->addChild(temp);
	CornShooter->setPosition(CornShooter->x, CornShooter->y);
	CornShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / CornShooter->AttackSpeed);
	CornShooter->autorelease();
	return CornShooter;
}