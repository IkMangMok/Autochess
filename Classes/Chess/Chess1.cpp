#include"Chess1.h"
#include<string>
#include"cocos2d.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;
#define schedule_selector(_SELECTOR) static_cast(&_SELECTOR)
Chess* Chess::create(const char *picture_filename)
{
	Chess* sprite = new Chess();
	if (sprite && sprite->initWithFile(picture_filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
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