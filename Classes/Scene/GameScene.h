#pragma once
#include "cocos2d.h"
#include "AutoChessScene.h"
#include "Map/MapLayer.h"
#include "Player/Player.h"
#include "Timer/RoundTimer.h"
#include "Sprite/GameSprite.h"
#include "AudioEngine.h"
#include "ChessPile/ChessPile.h"
#include "cocos-ext.h"              //����cocos-ext.hͷ�ļ�
#include <vector>
using namespace cocos2d::extension; //����cocos2d::extension�����ռ�

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

	//��ս������ƶ�����
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

	void Win();  //�жϴ򶷽���

	//���������
	void PlayerBuyChess(cocos2d::Ref* pSender, Control::EventType controlEvent);

	MapLayer* map = MapLayer::createMapLayer();
	Player* playerLayer = Player::createPlayer();
	GameSprite* gamesprite = GameSprite::createGameSprite();
	ChessPile* Chesspile = ChessPile::createChessPile();
	int turn = 0;
};