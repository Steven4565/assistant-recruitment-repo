#ifndef LOBBY_H
#define LOBBY_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "../globals.h"
#include "../utils/eventTimer.h"
#include "../events/eventStruct.h"
#include "../events/events.h"
#include "../utils/printUtils.h"
#include "../utils/inputUtils.h"
#include "../utils/gameUtils.h"
#include "game.h"

char *getLobbyMessage(Vector2D player)
{
	int x = player.x;
	int y = player.y;
	if (checkShops(lobbyShop, player))
	{
		return "Press SPACE to open item shop";
	}

	if (checkShops(lobbyUpgrade, player))
	{
		return "Press SPACE to open upgrades";
	}

	if (x == 5 && (y >= 9 && y <= 11))
	{
		return "Press SPACE to check leaderboards";
	}

	if (x == 17 && y == 20)
	{
		return "Press SPACE to exit";
	}

	if (x == 17 && y == 10)
	{
		return "Press SPACE to start game";
	}

	return "";
}

void renderLobby(Vector2D player)
{
	char *message;
	clrscr();
	for (int i = 0; i < lobby.h; i++)
	{
		for (int j = 0; j < lobby.w; j++)
		{
			char spriteChar = lobby.sprite[i][j];

			// render player
			if (j == player.x && i == player.y)
			{
				spriteChar = 'P';
			}

			// check for messages, set here
			message = getLobbyMessage(player);

			printf("%c", spriteChar);
		};
		// render messages next to board
		if (i == 10)
		{
			printf("\tPlayer: %d, %d", player.x, player.y);
		}
		else if (i == 15)
		{
			printf("\t%s", message);
		}
		puts("");
	}
}

void movePlayer(Vector2D *player, Vector2D input)
{
	// check for collission
	if (checkLobbyCollision(player->x + input.x, player->y + input.y))
	{
		// if no collision, move player
		player->x += input.x;
		player->y += input.y;
	}
}

void handleMoveVector(char inputChar, Vector2D *inputVector)
{
	switch (inputChar)
	{
	case 'w':
		inputVector->x = 0;
		inputVector->y = -1;
		return;
	case 'a':
		inputVector->x = -1;
		inputVector->y = 0;
		return;
	case 's':
		inputVector->x = 0;
		inputVector->y = 1;
		return;
	case 'd':
		inputVector->x = 1;
		inputVector->y = 0;
		return;
	default:
		return;
	}
}

void enterItemShop()
{
	// TODO: item shop
}

void enterUpgradeShop()
{
	// TODO: upgrade shop
}

void handleLobbyInteract(Vector2D player, char inputChar, bool *runLobby)
{
	int x = player.x;
	int y = player.y;

	if (checkShops(lobbyShop, player))
	{
		enterItemShop();
	}

	if (checkShops(lobbyUpgrade, player))
	{
		enterUpgradeShop();
	}

	if (x == 5 && (y >= 9 && y <= 11))
	{
		getLeaderboard();
	}

	if (x == 17 && y == 20)
	{
		*runLobby = false;
	}

	if (x == 17 && y == 10)
	{
		startEventLoop();
	}
}

void initLobby()
{
	lobbyData.playerData = currentPlayer;
}

void lobbyLoop()
{
	bool runLobby = true;
	Vector2D player = {17, 19};
	// TODO: initialize lobby here?
	initLobby();

	renderLobby(player);

	while (runLobby)
	{
		clrscr();
		renderLobby(player);

		Vector2D moveVector = {0, 0};
		char inputChar = getch();
		handleMoveVector(inputChar, &moveVector);

		// check for space (interact)
		if (inputChar == ' ')
			handleLobbyInteract(player, inputChar, &runLobby);
		// TODO: handle other inputs like backpack, talk
		movePlayer(&player, moveVector);

		usleep(10000);
	}
}

#endif