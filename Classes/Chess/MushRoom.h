#pragma once
#include"Chess.h"

class MushRoom :public Chess {
public:
	MushRoom();
	static MushRoom* createChess();
	CREATE_FUNC(MushRoom);
};
