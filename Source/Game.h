#pragma once
#include <Engine/OGLGame.h>
#include <string>
#include "Action.h"
#include<memory>
class Player;
class UIPanel;
class Enemy;
struct Font;
class Dungeon;
class Room;
enum class GameState
{
	MAIN_MENU = 0,
	PLAYING=1,
	GAME_OVER=2,
	EXIT=3

};



class DungeonDeathGame:
	public ASGE::OGLGame
{
public:
	
	DungeonDeathGame();
	~DungeonDeathGame();

	// Inherited via Game
	virtual bool run() override;

	// Inherited via OGLGame
	virtual bool init();
	bool movePlayer(Room*new_room);
	void processMoveAction(GameAction action);
	virtual void drawFrame();
	void processGameActions();
	void printToGamePanel(std::string&&str);
	void updateGame();
	void updateMenue();
	void updateGameOver();
	void Stateinput(int key ,int action);
private:
	int sate_callback_id = -1;
	int game_callback_id = -1;
	std::unique_ptr<UIPanel> panels[5];
	std::unique_ptr<Player>player_one = nullptr;
	std::unique_ptr<Enemy>enemy_bat = nullptr;
	std::unique_ptr<Dungeon>dungeon = nullptr;
	GameState game_state = GameState::MAIN_MENU;
};

