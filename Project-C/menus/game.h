#ifndef GAME_H
#define GAME_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "../utils/eventTimer.h"
#include "../events/eventStruct.h"
#include "../events/events.h"
#include "../globals.h"
#include "../utils/printUtils.h"
#include "../utils/inputUtils.h"
#include "../utils/gameUtils.h"
#include "../events/handlers/enemyHandler.h"

void render()
{
	char *message = "";
	clrscr();
	for (int i = 0; i < board.h; i++)
	{
		for (int j = 0; j < board.w; j++)
		{
			char spriteChar = getBoardChar(j, i);
			printf("%c", spriteChar);
		};
		// render messages next to board
		if (i == 15)
		{
			printf("\t%s", message);
		}
		puts("");
	}
}

void handleGameplayInput(char input, Vector2D *moveVector)
{
	if (input == ' ')
		return;

	if (input == 'w' || input == 'a' || input == 's' || input == 'd')
	{
		handleMoveVector(input, moveVector);
		return;
	}

	switch (input)
	{
	case 'g':
		// TODO: if has bomb, fire onbonb
		// else: fire onMessage("You don't have any bombs")
		break;
	case 'r':
		break;
	case 'f':
		break;
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	default:
		break;
	}
}

void gameLoop()
{
	// clear screen
	clrscr();
	// render
	render();

	// get input (if space then no input)
	char input = getKbdInput();

	// handle input
	Vector2D moveVector = {0, 0};
	handleGameplayInput(input, &moveVector);
	movePlayerNode(board, &game.currentPlayer.playerNode, moveVector);

	// if bomb => fire onbomb event

	// handle events
	// moveEnemies();
	// moveBullets(); // move bullets
	// checkBullets(); // kill enemy, reduce player health, remove bullets
}

// Functions

void initGame()
{
	Node playerNode = {{5, 5}, 5, 5};
	PlayerEntry currentPlayer = lobbyData.playerData;
	PlayerAttributes attr = {.xp = currentPlayer.xp,
													 .level = currentPlayer.level,
													 .money = currentPlayer.money,
													 .hp = currentPlayer.hp,
													 .armor = currentPlayer.armor,
													 .maxHp = currentPlayer.hp,
													 .maxEnergy = currentPlayer.energy,
													 .maxArmor = currentPlayer.armor};
	Player player = {
			.playerNode = playerNode,
			.attributes = attr,
	};

	game.enemyCount = 0;
	game.bulletCount = 0;
	game.currentPlayer = player;
}

void startEventLoop()
{
	bool endGame = false;

	initGame();

	Timer frame = {clock(), 40, 0};
	Timer enemy = {clock(), 4000, 0};
	while (!endGame)
	{
		setTimerInterval(&frame);
		setTimerInterval(&enemy);

		// MAIN LOOP
		runEvent(&frame, &gameLoop);

		// EMIT EVENTS
		emitEvent(&enemy, &(events.onEnemyEmitted));

		// for optimization
		usleep(30000);
	}
}

#endif