#include "RoundTimer.h"
#include"AppDelegate.h"
RoundTimer::RoundTimer()
{

}

RoundTimer::~RoundTimer()
{

}

bool RoundTimer::init(float time)
{
	pTime = time;
	label = Label::createWithTTF("Help", "fonts/Marker Felt.ttf", 24);
	label->setPosition(200, 200);
	this->addChild(label);
	this->scheduleUpdate();
	return true;

}
void RoundTimer::update(float delta)
{
	pTime -= delta;
	char* mtime = new char[10];
	sprintf(mtime, "%02d : %02d", (int)pTime / 60, (int)pTime % 60);
	label->setString(mtime);
}
RoundTimer* RoundTimer::create(float time)
{
	RoundTimer* roundtimer = new RoundTimer;
	if (roundtimer && roundtimer->init(time))
	{
		roundtimer->autorelease();
		return roundtimer;
	}
	else
	{
		delete roundtimer;
		roundtimer = NULL;
	}
	return NULL;
}
