#pragma once
#include "cocos2d.h"
#include "AutoChessScene.h"
#include "Player/Player.h"
#include "Timer/RoundTimer.h"
#include "Sprite/GameSprite.h"
#include "AudioEngine.h"
#include "ChessPile/ChessPile.h"
#include "cocos-ext.h"              //包含cocos-ext.h头文件
#include <vector>
using namespace cocos2d::extension; //引用cocos2d::extension命名空间

USING_NS_CC;

#define FightNumber 30

class GameScene : public AutoChess {
public:
	static GameScene* createScene(string& settingname);
	virtual bool init();
	GameScene();
	~GameScene();

private:
	RoundTimer* test_timer = RoundTimer::create(10);

	void update(float dt);
	CREATE_FUNC(GameScene);

	//备战期鼠标移动函数
	void ChessMoveInMouse();
	void SceneMouseBack(cocos2d::Ref* pSender);
	void onMouseScroll(Event* event);
	void onMouseMove(Event* event);
	void onMouseUp(Event* event);
	void onMouseDown(Event* event);
	Point MapJudge(Point point);
	IntMap MapIntReturn(Point point);
	int MouseToChess = -1;

	bool FindMouseTarget(ccArray* Array, EventMouse* e);
	void SoldChess(Chess* temp, ccArray* Array);
	
	void GameScene::addChess(PlayerData &playerdata);

	friend class Chess;
	friend class GameSprite;

	void Win();  //判断打斗结束
	void JudgeWin(PlayerData& playerdata, int sum[]);
	void WinRetain(ccArray* Array);

	void ToFightArray(Chess* chess, PlayerData& playerdata);
	void ToPlayerArray(Chess* chess, PlayerData& playerdata);

	string getName();

	MapLayer* map = MapLayer::createMapLayer();
	Player* playerLayer = Player::createPlayer(getName());
	GameSprite* gamesprite = GameSprite::createGameSprite();
	ChessPile* Chesspile = ChessPile::createChessPile();
	int turn = 0;

	Label* Coins = Label::createWithTTF(to_string(player1data.Gold), "fonts/Marker Felt.ttf", 24);  //临时记录
	
	friend class GameSprite;
};