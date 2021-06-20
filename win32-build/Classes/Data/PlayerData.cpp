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

void PlayerData::remain()
{
	PlayerArray = ccArrayNew(100);   //��ұ�ս������������
	FightArray = ccArrayNew(100);
	LifeLimit = 100;   //����ֵ����
	HealthValue = LifeLimit; //����ֵ
	Grade = 1; //��ҵȼ�
	ExperienceValue = 0;   //����ֵ
	Gold = 3000;  //���
	ToNextGrade = 2;
	occupied_slot = 0;
	is_package_opened = 0;
	for (int i = 0; i < 12; i++)
	{
		if (i < 3)
		{
			for (int j = 0; j < 4; j++)
			{
				packageSlot[i][j] = PackageSlot(0, 0);

			}
		}
		slotPoint[i] = Point(0, 0);
	}

}