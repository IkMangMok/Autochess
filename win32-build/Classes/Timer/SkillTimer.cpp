#include "SkillTimer.h"
#include"AppDelegate.h"
SkillTimer::SkillTimer()
{

}

SkillTimer::~SkillTimer()
{

}


void SkillTimer::update(float delta)
{
	pTime -= delta;
}
SkillTimer* SkillTimer::createTimer(float time)
{
	SkillTimer* SkillTimer = SkillTimer::create();
	SkillTimer->pTime = 5.0f;
	SkillTimer->retain();
	SkillTimer->autorelease();
	return SkillTimer;
}