#include"PlayerData.h"

PlayerData player1data;
PlayerData player2data;

void PlayerData::recover()
{
	Gold = Gold + std::min(Gold / 10 + 5, 12);
	ExperienceValue += 2;
	CountExperience();
}

void PlayerData::CountExperience()
{
	for (int i = 0;; i++)
	{
		int k = i + 1;
		if (ExperienceValue >= (i * i * i * 2 / 5 + 2 * i) && ExperienceValue < (k * k * k * 2 / 5 + 2 * k))
		{
			Grade = k;
			ToNextGrade = (k * k * k * 2 / 5 + 2 * k) - ExperienceValue;
			return;
		}
	}
}