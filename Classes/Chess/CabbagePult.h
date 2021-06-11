#pragma once
#include"Chess.h"

class CabbagePult :public Chess {
public:
	CabbagePult();
	static CabbagePult* createChess();
	CREATE_FUNC(CabbagePult);
};