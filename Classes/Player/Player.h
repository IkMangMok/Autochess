#pragma once
#include "cocos2d.h"
#include "string"
#include"Data/PlayerData.h"
#include"Scene/LoginScene.h"

using namespace cocos2d;
using namespace std;

class Player : public Layer {
public:
	static Player* createPlayer(string& name);
	virtual bool init();
	CREATE_FUNC(Player);
};
