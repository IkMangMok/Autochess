#pragma once
#include"Chess.h"

class MushRoom :public Chess {
public:
	MushRoom();
	static MushRoom* createChess();
<<<<<<< HEAD
=======
	void Skill();
>>>>>>> lx
	CREATE_FUNC(MushRoom);
};

class upgrade_MushRoom :public MushRoom {
public:
	upgrade_MushRoom();
	static upgrade_MushRoom* createChess();
	CREATE_FUNC(upgrade_MushRoom);
};

class _3star_MushRoom :public MushRoom {
public:
	_3star_MushRoom();
	static _3star_MushRoom* createChess();
	CREATE_FUNC(_3star_MushRoom);
};

