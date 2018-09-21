#include "Game.h"
#include "Constants.h"
#include "Font.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyType.h"
#include"Dungeon.h"
#include"Room.h"
#include <iostream>
#include <sstream>

#include <Engine/Input.h>
#include <Engine/Sprite.h>
#include<Engine/Keys.h>
//USER INTERFACE
#include "Panel.h"
#include "InputPanel.h"
#include "GamePanel.h"
#include "MapPanel.h"
#include "ViewportPanel.h"
#include "StatsPanel.h"
#include "Action.h"
#include "Actor.h"

DungeonDeathGame::DungeonDeathGame()
{

}
void DungeonDeathGame::processGameActions()
{
	if (game_action == GameAction::ATTACK)
	{
			if (player_one->isAlive())
			{

				if (enemy_bat->isAlive())
				{
					auto dmg = player_one->attack(enemy_bat.get());
					printToGamePanel("ave it");

					std::string dstr("you deal ");
					dstr += std::to_string(dmg);
					dstr += " damage";
					printToGamePanel(std::move(dstr));

					if (!enemy_bat->isAlive())
					{
						printToGamePanel(
							"the bat falls to the floor in a crumpled heap");
					}
					else
					{
						auto dmg = enemy_bat->attack(player_one.get());
						std::string dstr("you take ");
						dstr += std::to_string(dmg);
						dstr += " damage";
						printToGamePanel(std::move(dstr));

						player_one->loadAvatar(renderer);
						if (player_one->getHealth() <= 0)
						{
							printToGamePanel("Gratz you're dead");
							game_state = GameState::GAME_OVER;
						}
					}
				}
			}
	}
	else if(game_action==GameAction::NORTH)
	{
		processMoveAction(GameAction::NORTH);
	}
	else if (game_action == GameAction::EAST)
	{
		processMoveAction(GameAction::EAST);
	}
	else if (game_action == GameAction::WEST)
	{
		processMoveAction(GameAction::WEST);
	}
	else if (game_action == GameAction::SOUTH)
	{
		processMoveAction(GameAction::SOUTH);
	}
	else if (game_action == GameAction::INVENTORY)
	{
		printToGamePanel(player_one->getInventoryAsString());
	}
	if (game_action == GameAction::INVALID)
	{
		printToGamePanel("unsupported Action");
	}
	game_action = GameAction::NONE;
}

bool DungeonDeathGame::movePlayer(Room*new_room)
{
	if (!new_room)
	{
		return false;
	}
	player_one->setRoom(new_room);
	printToGamePanel("\n");
	printToGamePanel("you entered the" + new_room->GetName());
	printToGamePanel(std::string(new_room->GetDescription()));
	return true;
}
void DungeonDeathGame::processMoveAction(GameAction action)
{
	if (action == GameAction::NORTH)
	{
		auto&new_room = player_one->GetRoom()->GetNorth().room;
		if (!movePlayer(new_room))
		{
			printToGamePanel("you cannot move north");
		}
	}
	if (action == GameAction::EAST)
	{
		auto&new_room = player_one->GetRoom()->GetEast().room;
		if (!movePlayer(new_room))
		{
			printToGamePanel("you cannot move east");
		}
	}
	if (action == GameAction::WEST)
	{
		auto&new_room = player_one->GetRoom()->GetWest().room;
		if (!movePlayer(new_room))
		{
			printToGamePanel("you cannot move west");
		}
	}
	if (action == GameAction::SOUTH)
	{
		auto&new_room = player_one->GetRoom()->GetSouth().room;
		if (!movePlayer(new_room))
		{
			printToGamePanel("you cannot move south");
		}
	}

}
void DungeonDeathGame::updateMenue()
{
	beginFrame();
	renderer->setFont(Font::fonts[1]->id);

	renderer->renderText("Dungeon Death 2016", 0, 30, 1.0, ASGE::COLOURS::DARKORANGE);
	renderer->renderText("Welcome .\nAre you man or mouse ?", 200, 200, ASGE::COLOURS::STEELBLUE);
	endFrame();
}
void DungeonDeathGame::updateGame()
{
	processGameActions();
	beginFrame();
	drawFrame();
	endFrame();
}
void DungeonDeathGame::updateGameOver()
{
	beginFrame();
	renderer->setFont(Font::fonts[1]->id);

	renderer->renderText("I see you were a mouse ", 200, 200, ASGE::COLOURS::STEELBLUE);
	endFrame();
}


void DungeonDeathGame::Stateinput(int key, int action)
{
	if (action == ASGE::KEYS::KEY_PRESS&&game_state == GameState::MAIN_MENU)
	{
		game_state = GameState::PLAYING;
		auto intput_panel = static_cast<InputPanel*>(panels[4].get());
		game_callback_id = this->inputs->addCallbackFnc(&InputPanel::input, intput_panel);
	}
	else if(action == ASGE::KEYS::KEY_PRESS&&game_state == GameState::GAME_OVER)
	{
		game_state = GameState::EXIT;
		auto intput_panel = static_cast<InputPanel*>(panels[4].get());
		game_callback_id = this->inputs->addCallbackFnc(&InputPanel::input, intput_panel);
	}
}

bool DungeonDeathGame::init()
{
	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;
	if (!initAPI())
	{
		return false;
	}

	// load fonts
	Font::fonts[0] = new Font(renderer->loadFont("..\\..\\Resources\\Fonts\\DroidSansMono.ttf", 22), "default", 22);
	Font::fonts[1] = new Font(renderer->loadFont("..\\..\\Resources\\Fonts\\comic.ttf", 32), "heading", 32);
	Font::fonts[2] = new Font(renderer->loadFont("..\\..\\Resources\\Fonts\\comic.ttf", 16), "small", 16);

	renderer->setClearColour(ASGE::COLOURS::BLACK);
	dungeon = std::make_unique<Dungeon>();
	dungeon->creat();
	// create player
	player_one = std::make_unique<Player>(Player::PlayerClass::BARBARIAN);
	player_one->loadAvatar(renderer);
	player_one->setRoom(dungeon->GetRoom(0));

	EnemyType::load();
	//enemy_bat = std::make_unique<Enemy>();
	enemy_bat.reset(EnemyType::enemy_types[0].createEnemy());

	std::unique_ptr<GamePanel> game_panel;
	game_panel = std::make_unique<GamePanel>();
	game_panel->setPosX(1);
	game_panel->setPosY(70);
	game_panel->setHeight(35);
	game_panel->setWidth(35);

	std::unique_ptr<ViewportPanel>viewport_panel;
	viewport_panel= std::make_unique<ViewportPanel>();
	viewport_panel->setPosX((game_panel->getPosX() + (game_panel->getWidth() * BORDER_CELL_WIDTH) + PANEL_PADDING));
	viewport_panel->setPosY(340);
	viewport_panel->setWidth(20);
	viewport_panel->setHeight(20);
	viewport_panel->setObject(enemy_bat.get());

	std::unique_ptr<StatsPanel>stats_panel;
	stats_panel = std::make_unique<StatsPanel>();
	stats_panel->setPosX(viewport_panel->getPosX());
	stats_panel->setPosY(game_panel->getPosY());
	stats_panel->setWidth(viewport_panel->getWidth()*1.8);
	stats_panel->setHeight(game_panel->getHeight() - viewport_panel->getHeight());
	stats_panel->init(player_one.get());

	
	std::unique_ptr<MapPanel>map_panel;
	map_panel = std::make_unique<MapPanel>();
	map_panel->setPosX(viewport_panel->getPosX() + (viewport_panel->getWidth() * BORDER_CELL_WIDTH));
	map_panel->setPosY(viewport_panel->getPosY());
	map_panel->setWidth(stats_panel->getWidth() - viewport_panel->getWidth());
	map_panel->setHeight(game_panel->getHeight() - stats_panel->getHeight());

	std::unique_ptr<InputPanel>input_panel;
	input_panel = std::make_unique<InputPanel>();
	input_panel->setPosX(0);
	input_panel->setPosY(700);
	

	game_panel->addOutput("Welcome to the Dungeon of Death");
	game_panel->addOutput("You awake to find your self trap under ground you look around ");
	game_panel->addOutput(player_one->GetRoom()->GetDescription());

	//auto callbackid = this->inputs->addCallbackFnc(&InputPanel::input, input_panel.get());
	sate_callback_id = this->inputs->addCallbackFnc(&DungeonDeathGame::Stateinput, this);

	panels[0] = std::move(game_panel);
	panels[1] = std::move(viewport_panel);
	panels[2] = std::move(stats_panel);
	panels[3] = std::move(map_panel);
	panels[4] = std::move(input_panel);
	return true;

}

void DungeonDeathGame::drawFrame()
{
	renderer->setFont(Font::fonts[1]->id);
	renderer->renderText("Dungeon Death 2016", 0, 30, 1.0, ASGE::COLOURS::DARKORANGE);

	renderer->setFont(Font::fonts[0]->id);
	for (auto& panel : panels)
	{
		panel->render(renderer);
	}
}

void DungeonDeathGame::printToGamePanel(std::string&&str)
{
	auto panel = static_cast<GamePanel*>(panels[0].get());
	if(panel)
	{
		panel->addOutput(std::move(str));
	}
}

DungeonDeathGame::~DungeonDeathGame()
{
	

	for (auto& font : Font::fonts)
	{
		delete font;
		font = nullptr;
	}
}
bool DungeonDeathGame::run()
{
	while (!renderer->exit()&&game_state!=GameState::EXIT	)
	{
		if (game_state==GameState::MAIN_MENU)
		{
			updateMenue();
		}
		else if (game_state == GameState::PLAYING)
		{
			updateGame();
		}
		else if (game_state==GameState::GAME_OVER)
		{
			updateGameOver();
		}
		
		
	}

	return false;
}