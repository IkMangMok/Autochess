
#include "cocos2d.h"
#include "string"

using namespace cocos2d;
using namespace std;

class Chess :public Sprite {
private:
	int AttackDistance = 0;  //��������
	int Health = 0;          //����ֵ
	int Armor = 0;           //����
	float x = 0.;           //λ��
	float y = 0.;
public:
	//virtual bool init();
	static Chess* create(const char * picture_filename);
	void scan(float dt);       //�ƶ�
	void set(float x, float y);

	
};
