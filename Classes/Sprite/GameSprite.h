#pragma once
#include "cocos2d.h"
#include "Chess/Chess.h"
#include "Data/GameData.h"
#include "Data/PlayerData.h"
USING_NS_CC;



class GameSprite :public Layer
{
public:
	static GameSprite* createGameSprite();
	CREATE_FUNC(GameSprite);

	void ChessMove(Chess* chess);
	virtual bool init();
	void update(float dt);
	void buy(Point point);

};


