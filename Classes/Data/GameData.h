#pragma once
#include "cocos2d.h"
#include"Player/Player.h"

USING_NS_CC;

class GameData
{
public:
	//static GameData* createGameData();
	//CREATE_FUNC(GameData);
	//virtual bool init();
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

	friend class AutoChess;
	friend class scene1;
};

/*�ⲿ����ȫ�ֱ��� global_data*/
extern GameData global_data;
extern ccArray* pArray;
extern Player* player1;
