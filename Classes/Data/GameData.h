#pragma once
#include "cocos2d.h"
#include "Map/MapLayer.h"
USING_NS_CC;


//��ͼ��64*36
#define ChessNumber 35
#define OriginalChess 8
class GameData: Scene
{
public:
	static GameData* createGameData();
	CREATE_FUNC(GameData);
	virtual bool init();
	/* ��ȡ��ǰ��Ϸ���ݵĺ��� */
	/* functions to obtain the game data */
	/*int GetPlayerCoin() { return player_coin; }
	int GetPlayerLevel() { return player_level; }
	int GetPlayerExe() { return player_exe; }
	int GetPlayerBlood() { return player_blood; }*/
	int GetGameTurn() { return game_turn; }

    //��¼���ӵ�����
//private:

	/* ��ʼ�����л�����Ϣ */
	void GameStartInit();

	/* ��ǰ����ȫ����Ϣ */
	/* global data */

	
	/*int player_coin;
	int player_level;
	int player_exe;
	int player_blood;*/
	int game_turn = 0;

	/* �޸ĵ�ǰ��Ϸ���ݵĺ��� */
	/*void ChangePlayerCoin(int benefit) { player_coin += benefit; }
	void ChangePlayerExe(int benefit) { player_exe += benefit; }   //�������԰�level�ĸı��߼��Ž��������
	void ChangePlayerBlood(int hurt) { player_blood -= hurt; }  */   //ע���˺�������
	void ChangeGameTurn() { game_turn++; }

};

struct chessInfo
{
	int address = 0;
	std::string picture_name = "";
	int money = 0;
	bool buy = false;
};
/*�ⲿ����ȫ�ֱ��� global_data*/
extern GameData* global_data;

enum ChessType
{
	None = -1,
	sunflower,
	walnut,
	pealauncher,
	mushroom,
	cherrybomb,
	ga_peashooter,
	tomatoboom,
	chomper,
	//�������ֲ��
	upgrade_sunflower,
	upgrade_walnut,
	upgrade_pealauncher,
	upgrade_mushroom,
	upgrade_cherrybomb,
	upgrade_ga_peashooter,
	upgrade_tomatoboom,
	upgrade_chomper,
	_3star_sunflower,
	_3star_walnut,
	_3star_pealauncher,
	_3star_mushroom,
	_3star_cherrybomb,
	_3star_ga_peashooter,
	_3star_tomatoboom,
	_3star_chomper
};

extern const int PB[9][5];
extern const chessInfo chess_store[OriginalChess];
