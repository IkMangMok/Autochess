#pragma once
#include"Chess.h"

class PeaShooter :public Chess {

public:
	PeaShooter();
	static PeaShooter* createChess();
	void Skill();
	void update(float dt);
	CREATE_FUNC(PeaShooter);
};

class upgrade_PeaShooter :public PeaShooter {

public:
	upgrade_PeaShooter();
	static upgrade_PeaShooter* createChess();
	CREATE_FUNC(upgrade_PeaShooter);
};

class _3star_PeaShooter :public PeaShooter {

public:
	_3star_PeaShooter();
	static _3star_PeaShooter* createChess();
	CREATE_FUNC(_3star_PeaShooter);
};
