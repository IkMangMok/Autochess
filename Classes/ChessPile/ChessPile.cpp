#include"ChessPile.h"

void ChessPile::Bought(int Chess_name)
{
	chesspile[Chess_name]--;

}
void ChessPile::ToSellDistrict()   //��ҵȼ���ͬ�����ʲ�ͬ��������ʱ���þ�Ϊ20%
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