#include "Gun.h"

Gun* Gun::createGun()
{
	auto gun = Gun::create();
	gun->initWithFile("Gun.png");
	gun->retain();
	gun->type = 1;
	return gun;

}

/*对棋子进行加成*/
void Gun::EquipToChess(Chess* Owner)
{
	Owner->ChangeAttackDistance(addAttackDistance);
	Owner->ChangeHealthLimit(addHealthLimit);
	Owner->ChangeHealth(addHealth);
	Owner->ChangeArmor(addArmor);
	Owner->ChangeAttackSpeed(addAttackSpeed);
	Owner->ChangeDamage(addDamage);
}
