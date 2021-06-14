#pragma once
#include "cocos2d.h"
#include "Chess/ChessFile.h"

#include "Data/PlayerData.h"

USING_NS_CC;
using namespace std;


class GameSprite :public Layer
{
public:
	static GameSprite* createGameSprite();
	CREATE_FUNC(GameSprite);

	void ChessMove(Chess* chess, PlayerData& playerdata);
	void PlayerArrayInit(ccArray* Array);
	virtual bool init();
	void update(float dt);
	IntMap MapIntReturn(Point point);
private:
	void upgrade(PlayerData &playerdata);         //Æå×ÓÉý¼¶
	Chess* GameSprite::upgradeChessCreate(int type);

	friend class GameScene;
};


