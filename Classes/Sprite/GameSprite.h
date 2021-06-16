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


	/*PC_Player相关*/
	void pcShowPlayerArray();
	void pcShowFightArray();
	void pcRemovePlayerArray();
	void pcRomoveFightArray();
private:
	void upgrade(PlayerData &playerdata);         //棋子升级
	Chess* GameSprite::upgradeChessCreate(int type);

	friend class GameScene;
};


