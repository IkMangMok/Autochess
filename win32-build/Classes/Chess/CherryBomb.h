#pragma once
#include"Chess.h"

class CherryBomb :public Chess {
public:
	CherryBomb();
	static CherryBomb* createChess();
	void Skill();
	CREATE_FUNC(CherryBomb);
};

class upgrade_CherryBomb :public CherryBomb {
public:
	upgrade_CherryBomb();
	static upgrade_CherryBomb* createChess();
	CREATE_FUNC(upgrade_CherryBomb);
};

class _3star_CherryBomb :public CherryBomb {
public:
	_3star_CherryBomb();
	static _3star_CherryBomb* createChess();
	CREATE_FUNC(_3star_CherryBomb);
};