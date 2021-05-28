#include"TestChess.h"
#include"cocos2d.h"
#include"AppDelegate.h"
using namespace cocos2d;
USING_NS_CC;

TestChess::TestChess()
{
	 AttackDistance = 500;  
	 Health = 600;          
	 Damage = 80;
	 AttackSpeed = 1.0f;
}
TestChess* TestChess::createChess(string picture_name, float x1 = 0., float y1 = 0.)
{

	auto testchess = new TestChess();
	testchess->set(x1, y1);

	auto temp = Sprite::create(picture_name);

	testchess->addChild(temp);
	testchess->setPosition(testchess->x, testchess->y);
	testchess->schedule(CC_SCHEDULE_SELECTOR(Chess::Attack), 1 / testchess->AttackSpeed);
	testchess->autorelease();
	return testchess;

}