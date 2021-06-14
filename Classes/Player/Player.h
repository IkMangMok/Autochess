#pragma once
#include "cocos2d.h"
#include "string"
#include"Data/PlayerData.h"

using namespace cocos2d;
using namespace std;

class Player : public Layer {
private:
	
public:
	static Player* createPlayer();
	virtual bool init();
	CREATE_FUNC(Player);
};
