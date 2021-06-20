#include "GameData.h"

/*定义全局变量 global_data*/
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

const int PB[9][5] = { {100,0,0,0,0},{80,20,0,0,0},{75,20,5,0,0},{60,25,15,0,0},{45,30,20,5,0},
					  {35,33,25,7,0},{25,34,30,10,1},{20,25,35,15,5},{10,25,40,18,7} };         //商店概率

const chessInfo chess_store[OriginalChess] =
{ {walnut,"walnut.png",1} ,{pealauncher,"pealauncher.png",2},{mushroom,"Mushroom0.png",2}
	,{sunflower,"sunflower.png",1},{chomper,"Flower0.png",3 },{cherrybomb,"cherrybomb.png",3},
	{ga_peashooter,"ga_peashooter0.png",4},{tomatoboom,"tomatoboom0.png",5} };      //初步的棋子商店，后续可加上卡池功能
