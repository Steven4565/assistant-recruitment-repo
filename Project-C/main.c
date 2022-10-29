#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <malloc.h>

#include "config.h"

#include "utils/printUtils.h"
#include "utils/inputUtils.h"
#include "utils/fileUtils.h"
#include "utils/eventTimer.h"

#include "events/eventStruct.h"
#include "events/events.h"
#include "events/handlers/enemyHandler.h"

#include "menus/mainMenu.h"

#include "globals.h"

#include <unistd.h>

void init()
{
	// Initialize sprites
	loadSprite(&space1, "assets/space_1.txt");
	loadSprite(&space2, "assets/space_2.txt");
	loadSprite(&space3, "assets/space_3.txt");
	loadSprite(&space4, "assets/space_4.txt");
	loadSprite(&board, "assets/game.txt");
	loadSprite(&lobby, "assets/lobby.txt");
	loadSprite(&enemy1, "assets/enemy_1.txt");
	loadSprite(&enemy2, "assets/enemy_2.txt");
	loadSprite(&enemy3, "assets/enemy_3.txt");
	lobby.sprite[lobbyShop.y][lobbyShop.x] = 'I';
	lobby.sprite[lobbyUpgrade.y][lobbyUpgrade.x] = 'U';
	lobby.sprite[lobbyShop.y][lobbyShop.x] = 'I';
	lobby.sprite[lobbyUpgrade.y][lobbyUpgrade.x] = 'U';

	// Load player data from database
	loadDatabase();
}

int main()
{
	if (DEBUG)
	{
		char cwd[1000];
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printf("Current working dir: %s\n", cwd);
		}
		else
		{
			perror("getcwd() error");
		}
		// puts(cwd);
		// getchar();
	}

	init();

	menuLoop();
}
