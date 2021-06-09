#pragma once
#include"Chess.h"

class SunFlower :public Chess {
public:
	SunFlower();
	static SunFlower* createChess();
	CREATE_FUNC(SunFlower);
	
};