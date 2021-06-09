#pragma once
#include"Chess.h"

class CherryBomb :public Chess {
public:
	CherryBomb();
	static CherryBomb* createChess();
	CREATE_FUNC(CherryBomb);
};