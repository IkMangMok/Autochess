#pragma once
#include"Chess/ChessFile.h"
#include"Data/GameData.h"
#include"Data/PlayerData.h"

#include "cocos-ext.h"              //包含cocos-ext.h头文件
using namespace cocos2d::extension;





class ChessPile : public Layer {
private:

	int i1 = 0, i2 = 1, i3 = 2, i4 = 3, i5 = 4;    //记录坐标
	int x = 470;
	
	const chessInfo chess_store[OriginalChess] =
	{ {walnut,"walnut.png",1} ,{pealauncher,"pealauncher.png",2},{mushroom,"mushroom.png",2}
		,{sunflower,"sunflower.png",1},{cactus,"cactus.png",3 },{cherrybomb,"cherrybomb.png",3},
		{cornshooter,"cornshooter.png",2},{cabbagepult,"cabbagepult.png",2} };      //初步的棋子商店，后续可加上卡池功能

	const string chessValue[3] =
	{ "1 coin","2 coins","3 coins" };

	cocos2d::LayerColor* s_layer= LayerColor::create();

	
	Chess* ChessCreate(int i);
	
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
	void cover(float x, float y);
	void buy1(cocos2d::Ref* pSender);
	void buy2(cocos2d::Ref* pSender);
	void buy3(cocos2d::Ref* pSender);
	void buy4(cocos2d::Ref* pSender);
	bool ifCanBuy(int m);
};