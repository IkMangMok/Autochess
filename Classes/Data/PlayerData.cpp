#include"PlayerData.h"

PlayerData player1data;
PlayerData player2data;

void PlayerData::recover()
{
	Gold = Gold + Gold / 10 + 5;
	ExperienceValue += 2;
}