#include "SetTimer.h"

Layer* SetTimer::createSetTimer()
{
	return SetTimer::createSetTimer();
}
bool SetTimer::init()
{
	if (!Layer::init())
		return false;

	this->sec = 5;
	struct timeval now;
	gettimeofday(&now, NULL);
	this->oldTime = now.tv_sec;
	CCLOG("%d", this->sec);
	schedule(CC_SCHEDULE_SELECTOR(SetTimer::update));

	return true;
}
void SetTimer::update(float dt)
{
	struct timeval now;
	gettimeofday(&now, NULL);
	int nowTime = now.tv_sec;
	if (this->min != 0 || this->sec != 0)
	{
		if (nowTime - this->oldTime == 1)
		{
			if (this->sec == 0) 
			{
				this->min--;
				this->sec = 59;
				CCLOG("%d:%d", this->min, this->sec);
			}
			else if (this->sec != 0) 
			{
				this->sec--;
				CCLOG("%d:%d", this->min, this->sec);
			}
			this->oldTime = nowTime;   //�����趨���ö�ʱ��ǰ��ʱ��
		}
	}
	else if (this->min == 0 && this->sec == 0)
	{
		unschedule(CC_SCHEDULE_SELECTOR(SetTimer::update));
		CCLOG("END!");
	}
}