#include "cocos2d.h"


USING_NS_CC;

class SkillTimer :public cocos2d::Node
{
public:
	SkillTimer();

	virtual ~SkillTimer();

	static SkillTimer* createTimer(float time);

	void update(float delta);

	float pTime = 100;
	CREATE_FUNC(SkillTimer);


};