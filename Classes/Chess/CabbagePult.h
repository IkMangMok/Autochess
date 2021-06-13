#pragma once
#include"Chess.h"

class CabbagePult :public Chess {
public:
	CabbagePult();
	static CabbagePult* createChess();
	CREATE_FUNC(CabbagePult);
};

class upgrade_CabbagePult :public CabbagePult {
public:
	upgrade_CabbagePult();
	static upgrade_CabbagePult* createChess();
	CREATE_FUNC(upgrade_CabbagePult);
};