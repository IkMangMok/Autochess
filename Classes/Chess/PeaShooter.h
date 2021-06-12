#pragma once
#include"Chess.h"

class PeaShooter :public Chess {

public:
	PeaShooter();
	static PeaShooter* createChess();
	CREATE_FUNC(PeaShooter);
};

class upgrade_PeaShooter :public PeaShooter {

public:
	upgrade_PeaShooter();
	static upgrade_PeaShooter* createChess();
	CREATE_FUNC(upgrade_PeaShooter);
};
