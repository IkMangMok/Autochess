#include "GameData.h"

/*����ȫ�ֱ��� global_data*/
GameData* global_data = GameData::createGameData();


GameData* GameData::createGameData()
{
	return GameData::create();
}

bool GameData::init()
{
	if (!Scene::init())
		return false;
	return true;
}

void GameData::GameStartInit()
{
	/*player_coin = 0;
	player_level = 1;
	player_exe = 0;
	player_blood = 100;*/
	game_turn = 0;
}


ccArray* FightArray = ccArrayNew(100);    //���е���������
ccArray* PlayerArray = ccArrayNew(100);   //��ս������������
ccArray* ComputerArray = ccArrayNew(100); //������������
int chesspile[10];          //�ƶ�
bool HaveNewFightChess = 0;
