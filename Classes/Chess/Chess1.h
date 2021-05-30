
#include "cocos2d.h"
#include "string"

using namespace cocos2d;
using namespace std;

class Chess :public Sprite {
private:
	int AttackDistance;  //攻击距离
	int Health;          //生命值
	int Armor;           //护甲
	float AttackSpeed;   //攻击速度
	float x = 0.;           //位置
	float y = 0.;
	
	
public:
	//virtual bool init();
	Chess* AttackTarget = NULL;   //攻击目标
	static Chess* createChess(string picture_name, float x, float y);
	void set(float x, float y);
	void set(Point point);
	Point getPosition();
};
