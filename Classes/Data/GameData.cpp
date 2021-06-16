#include "GameData.h"

/*定义全局变量 global_data*/
GameData* global_data = GameData::createGameData();
ccArray* pArray = ccArrayNew(1000);

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
	player_coin = 0;
	player_level = 1;
	player_exe = 0;
	player_blood = 100;
	game_turn = 0;

}
