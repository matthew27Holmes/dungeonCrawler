//int main(int argc, char **argv)
//{
//	return 0;
//}

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Engine/Platform.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	DungeonDeathGame game;
	game.init();
	return game.run();
}