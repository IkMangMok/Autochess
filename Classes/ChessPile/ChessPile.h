#pragma once
#include"Chess/ChessFile.h"
#include"Data/GameData.h"
#include"Data/PlayerData.h"

#include "cocos-ext.h"              //包含cocos-ext.h头文件
using namespace cocos2d::extension;





class ChessPile : public Layer {
private:

	int x = 470;

	const string chessValue[5] =
	{ "1 coin","2 coins","3 coins","4 coins","5 coins" };

	cocos2d::Layer* s_layer= Layer::create();

	
	Chess* ChessCreate(int i);
	
public:	
	static ChessPile* createChessPile();
	
	CREATE_FUNC(ChessPile);
	virtual bool init();
	ChessPile();

	void chessStore();
	void refresh1(cocos2d::Ref* pSender);  //重载函数
	void refresh(PlayerData &playerdata);
	void openChessStore();
	void closeChessStore();
	void storeChess(int i);
	void closeLayer(cocos2d::Ref* pSender);
	void openLayer(cocos2d::Ref* pSender);
	void cover(float x, float y);
	void buy1(cocos2d::Ref* pSender);
	void buy2(cocos2d::Ref* pSender);
	void buy3(cocos2d::Ref* pSender);
	void buy4(cocos2d::Ref* pSender);
	bool ifCanBuy(int m, PlayerData& playerdata);
	friend class PC_Player;
};