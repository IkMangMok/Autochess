#pragma once
#include"Chess.h"

class TomatoBoom :public Chess {
public:
	TomatoBoom();
	static TomatoBoom* createChess();
	void Skill();
	CREATE_FUNC(TomatoBoom);
};

class upgrade_TomatoBoom :public TomatoBoom {
public:
	upgrade_TomatoBoom();
	static upgrade_TomatoBoom* createChess();
	CREATE_FUNC(upgrade_TomatoBoom);
};

class _3star_TomatoBoom :public TomatoBoom {
public:
	_3star_TomatoBoom();
	static _3star_TomatoBoom* createChess();
	CREATE_FUNC(_3star_TomatoBoom);
}; 
