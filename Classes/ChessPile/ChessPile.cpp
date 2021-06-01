#include"ChessPile.h"

void ChessPile::Bought(int Chess_name)
{
	chesspile[Chess_name]--;

}
void ChessPile::ToSellDistrict()   //玩家等级不同，几率不同，这里暂时采用均为20%
{
	int a = rand() % 100;
	if (a < 20)
		;
	else if (a - 20 < 20)
		;
	else if (a - 40 < 20)
		;
	else if (a - 60 < 20)
		;
	else
		;
}