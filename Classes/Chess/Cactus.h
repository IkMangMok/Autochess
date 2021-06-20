#pragma once
#include"Chess.h"

class Cactus :public Chess {
public:
	Cactus();
	static Cactus* createChess();
	void Skill();
	CREATE_FUNC(Cactus);
};

class upgrade_Cactus :public Cactus {
public:
	upgrade_Cactus();
	static upgrade_Cactus* createChess();
	CREATE_FUNC(upgrade_Cactus);
};

class _3star_Cactus :public Cactus {
public:
	_3star_Cactus();
	static _3star_Cactus* createChess();
	CREATE_FUNC(_3star_Cactus);
};