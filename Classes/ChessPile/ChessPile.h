#pragma once
#include"Chess/ChessFile.h"
#include"Data/GameData.h"
#include"Data/PlayerData.h"
#include "cocos-ext.h"              //包含cocos-ext.h头文件
using namespace cocos2d::extension;

#define ChessNumber 10

struct chessInfo
{
	string address;
	int money;
	bool buy = false;
};

class ChessPile : public Layer {
private:
	chessInfo Used[4];
	int i1 = 0, i2 = 1, i3 = 2, i4 = 3;
	int x = 470;
	bool flag = 1;
	const chessInfo chess_store[8] =
	{ {"walnut.png",1},{"pealauncher.png",2},{"mushroom.png",2},{"sunflower.png",1},{"cactus.png",3 },{"cherrybomb.png",3},
		{"cornshooter.png",2},{"cabbagepult.png",2} };

	const string chessValue[3] =
	{ "1 coin","2 coins","3 coins" };

	cocos2d::LayerColor* s_layer;
	
public:	
	static ChessPile* createChessPile();
	
	CREATE_FUNC(ChessPile);
	virtual bool init();
	ChessPile();

	void chessStore(cocos2d::Ref* pSender);
	void openChessStore();
	void closeChessStore();
	void storeChess(int i);
	void closeLayer(cocos2d::Ref* pSender);
	void buy1(cocos2d::Ref* pSender);
	void buy2(cocos2d::Ref* pSender);
	void buy3(cocos2d::Ref* pSender);
	void buy4(cocos2d::Ref* pSender);
};