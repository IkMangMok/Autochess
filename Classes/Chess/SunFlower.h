#pragma once
#include"Chess.h"

class SunFlower :public Chess {
public:
	SunFlower();
	static SunFlower* createChess();
	CREATE_FUNC(SunFlower);
	
};

class upgrade_SunFlower :public SunFlower {
public:
	upgrade_SunFlower();
	static upgrade_SunFlower* createChess();
	CREATE_FUNC(upgrade_SunFlower);
};