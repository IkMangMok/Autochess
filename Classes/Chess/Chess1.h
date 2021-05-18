
#include "cocos2d.h"
#include "string"

using namespace cocos2d;
using namespace std;

class Chess :public Sprite {
private:
	int AttackDistance;  //攻击距离
	int Health;          //生命值
	int Armor;           //护甲
	float x = 0.;           //位置
	float y = 0.;
public:
	//virtual bool init();
	static Chess* createChess(string picture_name, float x, float y);
	void scan(float dt);       //移动
	void set(float x, float y);

	
};
