#pragma once
#include"Chess.h"

class Cactus :public Chess {
public:
	Cactus();
	static Cactus* createChess();
	CREATE_FUNC(Cactus);
};

class upgrade_Cactus :public Cactus {
public:
	upgrade_Cactus();
	static upgrade_Cactus* createChess();
	CREATE_FUNC(upgrade_Cactus);
};