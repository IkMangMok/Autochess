#include "Equipment.h"

/*对棋子进行加成*/
void Equipment::EquipToChess(Chess* Owner)
{
	Owner->ChangeAttackDistance(addAttackDistance);
	Owner->ChangeHealthLimit(addHealthLimit);
	Owner->ChangeHealth(addHealth);
	Owner->ChangeArmor(addArmor);
	Owner->ChangeAttackSpeed(addAttackSpeed);
	Owner->ChangeDamage(addDamage);
}