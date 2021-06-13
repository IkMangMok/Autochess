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
	char* mtime = new char[10];
	sprintf(mtime, "%02d : %02d", (int)pTime / 60, (int)pTime % 60);
	
}
SkillTimer* SkillTimer::createTimer(float time)
{
	SkillTimer* SkillTimer = SkillTimer::create();
	SkillTimer->pTime = 5.0f;
	SkillTimer->autorelease();
	return SkillTimer;
}