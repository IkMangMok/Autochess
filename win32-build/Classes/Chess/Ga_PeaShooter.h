#pragma once
#include"Chess.h"

class Ga_PeaShooter :public Chess {
public:
	Ga_PeaShooter();
	static Ga_PeaShooter* createChess();
	CREATE_FUNC(Ga_PeaShooter);
	void update(float dt);
	void Skill();
};

class upgrade_Ga_PeaShooter :public Ga_PeaShooter {
public:
	upgrade_Ga_PeaShooter();
	static upgrade_Ga_PeaShooter* createChess();
	CREATE_FUNC(upgrade_Ga_PeaShooter);
};

class _3star_Ga_PeaShooter :public Ga_PeaShooter {
public:
	_3star_Ga_PeaShooter();
	static  _3star_Ga_PeaShooter* createChess();
	CREATE_FUNC(_3star_Ga_PeaShooter);
};