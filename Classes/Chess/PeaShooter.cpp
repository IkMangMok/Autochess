#include"PeaShooter.h"
#include"cocos2d.h"
#include"AppDelegate.h"
using namespace cocos2d;
USING_NS_CC;

PeaShooter::PeaShooter()
{
	 AttackDistance = 450;  
	 Health = 600;          
	 HealthLimit = Health;
	 Damage = 80;
	 Armor = 10;
	 AttackSpeed = 1.0f;
	 CoinsNeeded = 2;
}
PeaShooter* PeaShooter::createChess()
{

	auto peaShooter = PeaShooter::create();

	auto temp = Sprite::create("pealauncher.png");
	peaShooter->width = temp->getContentSize().width;
	peaShooter->height = temp->getContentSize().height;
	peaShooter->addChild(temp);
	peaShooter->setPosition(peaShooter->x, peaShooter->y);
	peaShooter->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / peaShooter->AttackSpeed);
	peaShooter->autorelease();
	return peaShooter;

}