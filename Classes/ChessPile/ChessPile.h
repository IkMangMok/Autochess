#pragma once
#include"Chess/ChessFile.h"
#include"Data/GameData.h"
#include"Data/PlayerData.h"
#include"Map/MapLayer.h"
#include "cocos-ext.h"              //����cocos-ext.hͷ�ļ�
using namespace cocos2d::extension;

#define ChessNumber 10

struct chessInfo
{
	int address = 0;
	string picture_name = "";
	int money = 0;
	bool buy = false;
};

class ChessPile : public Layer {
private:
	chessInfo Used[4];
	int i1 = 0, i2 = 1, i3 = 2, i4 = 3;    //��¼����
	int x = 470;
	
	const chessInfo chess_store[8] =
	{ {walnut,"walnut.png",1} ,{pealauncher,"pealauncher.png",2},{mushroom,"mushroom.png",2}
		,{sunflower,"sunflower.png",1},{cactus,"cactus.png",3 },{cherrybomb,"cherrybomb.png",3},
		{cornshooter,"cornshooter.png",2},{cabbagepult,"cabbagepult.png",2} };      //�����������̵꣬�����ɼ��Ͽ��ع���

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
	bool ifCanBuy();
};