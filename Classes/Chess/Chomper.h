#pragma once
#include"Chess.h"

class Chomper :public Chess {
public:
	Chomper();
	static Chomper* createChess();
	void Skill();
	CREATE_FUNC(Chomper);
};

class upgrade_Chomper :public Chomper {
public:
	upgrade_Chomper();
	static upgrade_Chomper* createChess();
	CREATE_FUNC(upgrade_Chomper);
};

class _3star_Chomper :public Chomper {
public:
	_3star_Chomper();
	static _3star_Chomper* createChess();
	CREATE_FUNC(_3star_Chomper);
};
