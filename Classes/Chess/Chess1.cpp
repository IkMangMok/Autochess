#include"Chess1.h"
#include<string>
#include"cocos2d.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;
#define schedule_selector(_SELECTOR) static_cast(&_SELECTOR)
Chess* Chess::createChess(string picture_name, float x1 = 0., float y1 = 0.)
{

	auto chess = new  Chess();
	chess->set(x1, y1);
	auto temp = Sprite::create("person.jpg");

	chess->addChild(temp);
	chess->setPosition(chess->x, chess->y);
	//chess->scheduleUpdate();
	chess->schedule(CC_SCHEDULE_SELECTOR(Chess::update), 0.01f);
	chess->autorelease();
	return chess;
	
}
void Chess::scan(float dt)
{
	x+=1;
	y+=1;
	setPosition(x, y);
}

void Chess::set(float x1 = 0, float y1 = 0)
{
	x = x1;
	y = y1;
}