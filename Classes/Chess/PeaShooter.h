#pragma once
#include"Chess.h"

class PeaShooter :public Chess {


public:
	PeaShooter();
	static PeaShooter* createChess(string picture_name, float x, float y);
	CREATE_FUNC(PeaShooter);
};
