#pragma once
#include"Chess/ChessFile.h"
#define ChessNumber 10
class ChessPile {
private:
	int chesspile[ChessNumber];    //��¼�������ӵ�����
public:
	void Bought(int Chess_name);    //��
	void Sold();      //��
	void ToSellDistrict();  //���뱸ս��
};