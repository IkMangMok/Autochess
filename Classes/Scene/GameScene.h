#pragma once
#include "cocos2d.h"
#include "AutoChessScene.h"
#include "Player/Player.h"
#include "Timer/RoundTimer.h"
#include "Sprite/GameSprite.h"
#include "AudioEngine.h"
#include "PC_Player/PC_Player.h"
#include "cocos-ext.h"              //包含cocos-ext.h头文件
#include <vector>
#include "HelpAndSetLayer.h"
#include "Equipment/EquipmentFile.h"
using namespace cocos2d::extension; //引用cocos2d::extension命名空间

USING_NS_CC;

#define FightNumber 70

class GameScene : public AutoChess {
public:
	static GameScene* createScene(string& settingname);
	virtual bool init();
	string getName();
	GameScene();
	~GameScene();

private:
	/**********计时器及Update**************/
	RoundTimer* test_timer = RoundTimer::create(10);
	void update(float dt);
	void TurnInfoInit();
	CREATE_FUNC(GameScene);

	//备战期鼠标移动函数
	void ChessMoveInMouse();
	void onMouseScroll(Event* event);
	void onMouseMove(Event* event);
	void onMouseUp(Event* event);
	void onMouseDown(Event* event);
	void GameStartMouseInit();
	Point MapJudge(Point point);
	int MouseToChess = -1;
	//整合函数
	bool FindMouseTarget(ccArray* Array, EventMouse* e);
	void SoldChess(Chess* temp, ccArray* Array, PlayerData& playerdata);
	
	void GameScene::addChess(PlayerData& playerdata, int playerinfo);


	void Win();  //判断打斗结束
	void JudgeWin(PlayerData& playerdata, int sum[]);
	void WinRetain(ccArray* Array);

	void ToFightArray(Chess* chess, PlayerData& playerdata);
	void ToPlayerArray(Chess* chess, PlayerData& playerdata);

	/***********所需子Layer************/
	MapLayer* map = MapLayer::createMapLayer();
	Player* playerLayer = Player::createPlayer(getName());
	GameSprite* gamesprite = GameSprite::createGameSprite();
	ChessPile* Chesspile = ChessPile::createChessPile();
	HelpAndSetLayer* hasl = HelpAndSetLayer::createLayer();

	/***********电脑玩家相关************/
	bool PC_ShowFlag = 1;


	int turn = 0;
	/*装备系统*/
	Package* layerPackage = Package::createPackage();
	bool EquipSearchChess(const float EquipX, const float EquipY, const int EquipIndex);
	int MouseSelectedEquip = -1;

	friend class GameSprite;
	friend class Chess;
	friend class GameSprite;

};