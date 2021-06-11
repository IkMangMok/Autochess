#pragma once
#include "cocos2d.h"
#include "AutoChessScene.h"
#include "Player/Player.h"
#include "Timer/RoundTimer.h"
#include "Sprite/GameSprite.h"
#include "AudioEngine.h"
#include "ChessPile/ChessPile.h"
#include "cocos-ext.h"              //����cocos-ext.hͷ�ļ�
#include <vector>

#include "Equipment/Package.h"
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

	/*TimerSystem*/
	RoundTimer* test_timer = RoundTimer::create(20);
	void TurnInfoInit();

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
	void SoldChess(Chess* temp, int i, ccArray* Array);
	friend class Chess;
	friend class GameSprite;

	void Win();  //�жϴ򶷽���

	MapLayer* map = MapLayer::createMapLayer();
	Player* playerLayer = Player::createPlayer();
	GameSprite* gamesprite = GameSprite::createGameSprite();
	ChessPile* Chesspile = ChessPile::createChessPile();
	int turn = 0;

	/*Equipment System*/
	Package* package1 = Package::createPackage(); //1�ű���
	bool EquipSearchChess(const float EquipX, const float EquipY, const int EquipIndex);
	int MouseSelectedEquip = -1;
};