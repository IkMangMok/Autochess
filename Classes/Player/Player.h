#pragma once
#include "cocos2d.h"
#include"Data/PlayerData.h"

using namespace cocos2d;
using namespace std;

class Player : public Layer {
private:
	virtual bool init();
	
public:
	static Player* createPlayer();
	CREATE_FUNC(Player);

	void ShowData();
};
