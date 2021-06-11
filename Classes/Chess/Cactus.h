#pragma once
#include"Chess.h"

class Cactus :public Chess {
public:
	Cactus();
	static Cactus* createChess();
	CREATE_FUNC(Cactus);
};