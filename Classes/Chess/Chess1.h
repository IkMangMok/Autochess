
#include "cocos2d.h"
#include "string"

using namespace cocos2d;
using namespace std;

class Chess :public Sprite {
private:
	int AttackDistance = 0;  //攻击距离
	int Health = 0;          //生命值
	int Armor = 0;           //护甲
	float x = 0.;           //位置
	float y = 0.;
public:
	//virtual bool init();
	static Chess* create(const char * picture_filename);
	void scan(float dt);       //移动
	void set(float x, float y);

	
};
