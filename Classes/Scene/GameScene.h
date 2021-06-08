#pragma once
#include "cocos2d.h"
#include "AutoChessScene.h"
#include "Map/MapLayer.h"
#include "Player/Player.h"
#include "Timer/RoundTimer.h"
#include "Sprite/GameSprite.h"
#include "AudioEngine.h"
#include "ChessPile/ChessPile.h"
#include "cocos-ext.h"              //包含cocos-ext.h头文件
#include <vector>
using namespace cocos2d::extension; //引用cocos2d::extension命名空间

USING_NS_CC;

struct IntMap {
	IntMap(int x1, int y1) { x = x1; y = y1; }
	int x;
	int y;
};

struct _map {
	float x;
	float y;
};

class GameScene : public AutoChess {
public:
	static GameScene* createScene();
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
	friend class Chess;
	friend class GameSprite;

	void Win();  //判断打斗结束

	//玩家买棋子
	void PlayerBuyChess(cocos2d::Ref* pSender, Control::EventType controlEvent);

	MapLayer* map = MapLayer::createMapLayer();
	Player* playerLayer = Player::createPlayer();
	GameSprite* gamesprite = GameSprite::createGameSprite();
	ChessPile* Chesspile = ChessPile::createChessPile();
	int turn = 0;
};