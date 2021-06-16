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

	auto temp = Sprite::create(picture_name);

	chess->addChild(temp);
	chess->setPosition(chess->x, chess->y);
	chess->scheduleUpdate();
	chess->autorelease();
	return chess;
	
}


void Chess::set(float x1 = 0, float y1 = 0)  //传入数值，有两种重载形式
{
	x = x1;
	y = y1;
}
void Chess::set(Point point)
{
	x = point.x;
	y = point.y;
}

Point Chess::getPosition()
{
	return Point(x, y);
}

