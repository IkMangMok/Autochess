#pragma once
#include "cocos2d.h"
#include "AutoChessScene.h"
#include "Player/Player.h"
#include "Timer/RoundTimer.h"
#include "Sprite/GameSprite.h"
#include "AudioEngine.h"
#include "PC_Player/PC_Player.h"
#include "cocos-ext.h"              //����cocos-ext.hͷ�ļ�
#include <vector>
#include "HelpAndSetLayer.h"
using namespace cocos2d::extension; //����cocos2d::extension�����ռ�

USING_NS_CC;

#define FightNumber 30

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

	bool FindMouseTarget(ccArray* Array, EventMouse* e);
	void SoldChess(Chess* temp, ccArray* Array);
	
	void GameScene::addChess(PlayerData& playerdata, int playerinfo);

	friend class Chess;
	friend class GameSprite;

	void Win();  //�жϴ򶷽���
	void JudgeWin(PlayerData& playerdata, int sum[]);
	void WinRetain(ccArray* Array);

	void ToFightArray(Chess* chess, PlayerData& playerdata);
	void ToPlayerArray(Chess* chess, PlayerData& playerdata);

	MapLayer* map = MapLayer::createMapLayer();
	Player* playerLayer = Player::createPlayer();
	GameSprite* gamesprite = GameSprite::createGameSprite();
	ChessPile* Chesspile = ChessPile::createChessPile();
	HelpAndSetLayer* hasl = HelpAndSetLayer::createLayer();
	int turn = 0;
	bool PC_ShowFlag = 1;
	
	
	friend class GameSprite;
};