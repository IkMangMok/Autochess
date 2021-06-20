#pragma once
#include"Chess.h"

class Cactus :public Chess {
public:
	Cactus();
	static Cactus* createChess();
<<<<<<< HEAD
=======
	void Skill();
>>>>>>> lx
	CREATE_FUNC(Cactus);
};

class upgrade_Cactus :public Cactus {
public:
	upgrade_Cactus();
	static upgrade_Cactus* createChess();
	CREATE_FUNC(upgrade_Cactus);
<<<<<<< HEAD
=======
};

class _3star_Cactus :public Cactus {
public:
	_3star_Cactus();
	static _3star_Cactus* createChess();
	CREATE_FUNC(_3star_Cactus);
>>>>>>> lx
};