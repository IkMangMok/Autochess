#include "cocos2d.h"


USING_NS_CC;

class SkillTimer :public cocos2d::Node
{
public:
	SkillTimer();

	virtual ~SkillTimer();

	static SkillTimer* createTimer(float time);

	void update(float dt);

	float pTime = 100.f;
	CREATE_FUNC(SkillTimer);


};