#pragma once
#include"Chess/ChessFile.h"
#define ChessNumber 10
class ChessPile {
private:
	int chesspile[ChessNumber];    //记录各种棋子的数量
public:
	void Bought(int Chess_name);    //买
	void Sold();      //卖
	void ToSellDistrict();  //放入备战区
};