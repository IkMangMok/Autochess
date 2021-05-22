
#include "cocos2d.h"
#include "string"

using namespace cocos2d;
using namespace std;

class Chess :public Sprite {
private:
	int AttackDistance;  //��������
	int Health;          //����ֵ
	int Armor;           //����
	float AttackSpeed;   //�����ٶ�
	float x = 0.;           //λ��
	float y = 0.;
	
	
public:
	//virtual bool init();
	Chess* AttackTarget = NULL;   //����Ŀ��
	static Chess* createChess(string picture_name, float x, float y);
	void set(float x, float y);
	void set(Point point);
	Point getPosition();
};
