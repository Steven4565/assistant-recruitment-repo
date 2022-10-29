#ifndef GAME_H
#define GAME_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "../utils/eventTimer.h"
#include "../globals.h"
#include "../utils/printUtils.h"
#include "../utils/inputUtils.h"
#include "../utils/gameUtils.h"
#include "../events/handlers.h"

void render()
{
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
			printf("\t%s", game.message);
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

	Timer frameTimer = {clock(), 40, 0, true};
	Timer enemyTimer = {clock(), 4000, 0, true};
	Timer resetMessageTimer = {clock(), 1000, 0, false};
	game.timers.frameTimer = frameTimer;
	game.timers.enemyTimer = enemyTimer;
	game.timers.resetMessageTimer = resetMessageTimer;

	game.message = "";
}

void gameLoop()
{
	// Render
	clrscr();
	render();

	// Get input (if space then no input)
	char input = getKbdInput();
	Vector2D moveVector = {0, 0};
	handleGameplayInput(input, &moveVector);
	movePlayerNode(board, &game.currentPlayer.playerNode, moveVector);

	// if bomb => fire emit onBomb event

	// HANDLE EVENTS (handle only if the flag is on, then turn flag off)
	handleMessageReset();
	// moveEnemies();
	// moveBullets(); // move bullets
	// checkBullets(); // kill enemyTimer, reduce player health, remove bullets
}

void startEventLoop()
{
	bool endGame = false;

	initGame();
	while (!endGame)
	{
		// updates timer msec
		setTimerInterval(&game.timers.frameTimer);
		setTimerInterval(&game.timers.enemyTimer);
		setTimerInterval(&game.timers.resetMessageTimer);

		// turns the bool on when msec > delay, resets msec
		runEvent(&game.timers.frameTimer, &gameLoop);
		setEventFlag(&game.timers.enemyTimer, &events.onEnemyEmitted);
		setEventFlag(&game.timers.enemyTimer, &events.onResetMessageEmitted);

		// for optimization
		usleep(20000);
	}
}

#endif