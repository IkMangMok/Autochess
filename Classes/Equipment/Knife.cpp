#include "Knife.h"
#include "Gun.h"

Knife* Knife::createKnife()
{
	auto knife = Knife::create();
	knife->initWithFile("Knife.png");
	knife->retain();
	knife->type = 2;
	return knife;

}

/*�����ӽ��мӳ�*/
void Knife::EquipToChess(Chess* Owner)
{
	Owner->ChangeAttackDistance(addAttackDistance);
	Owner->ChangeHealthLimit(addHealthLimit);
	Owner->ChangeHealth(addHealth);
	Owner->ChangeArmor(addArmor);
	Owner->ChangeAttackSpeed(addAttackSpeed);
	Owner->ChangeDamage(addDamage);
}