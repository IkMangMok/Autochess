#pragma once
#include"Chess.h"

class MushRoom :public Chess {
public:
	MushRoom();
	static MushRoom* createChess();
	CREATE_FUNC(MushRoom);
};

class upgrade_MushRoom :public MushRoom {
public:
	upgrade_MushRoom();
	static upgrade_MushRoom* createChess();
	CREATE_FUNC(upgrade_MushRoom);
};
