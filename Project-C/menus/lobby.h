#ifndef LOBBY_H
#define LOBBY_H

#include <time.h>
#include <stdio.h>
#include "../globals.h"
#include "../utils/eventTimer.h"
#include "../events/eventStruct.h"
#include "../events/events.h"
#include "../globals.h"
#include "../utils/printUtils.h"
#include "../utils/inputUtils.h"

void renderLobby(Vector2D player)
{
	char *message = "";
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
			printf("%c", spriteChar);
		}
		// render messages next to board
		if (i == 10)
		{
			printf("\tPlayer: %d, %d", player.x, player.y);
		}
		puts("");
	}
}

void movePlayer(Vector2D *player, Vector2D input)
{
	// check for collission
	// if no collision, move player
	player->x += input.x;
	player->y += input.y;
}

void handleLobbyInput(char inputChar, Vector2D *inputVector)
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
		inputVector->x = 0;
		inputVector->y = 0;
		return;
	}
}

void lobbyLoop()
{
	bool runLobby = true;
	Vector2D player = {17, 19};

	char *lobbyMessages;
	renderLobby(player);

	while (runLobby)
	{
		clrscr();
		renderLobby(player);
		Vector2D input = {0, 0};
		handleLobbyInput(getch(), &input);
		movePlayer(&player, input);
	}
}

#endif