#pragma once
#include"Chess.h"

class CherryBomb :public Chess {
public:
	CherryBomb();
	static CherryBomb* createChess();
	CREATE_FUNC(CherryBomb);
};

class upgrade_CherryBomb :public CherryBomb {
public:
	upgrade_CherryBomb();
	static upgrade_CherryBomb* createChess();
	CREATE_FUNC(upgrade_CherryBomb);
};