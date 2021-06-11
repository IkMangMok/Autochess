#pragma once
#include"Chess.h"

class PeaShooter :public Chess {

public:
	PeaShooter();
	static PeaShooter* createChess();
	CREATE_FUNC(PeaShooter);
};
