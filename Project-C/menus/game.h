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

void gameLoop()
{
	// clear screen
	clrscr();

	// get input (if space then no input)
	char input = getKbdInput();

	// handle input
	handleGameplayInput(input);
	// if bomb => fire onbomb event

	// handle events
	// moveEnemies();
	// moveBullets(); // move bullets
	// checkBullets(); // kill enemy, reduce player health, remove bullets

	// render
	render();
}

void initGame()
{
	Node playerNode = {{5, 5}, 5, 5};
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
	printf("%d\n", game.currentPlayer.attributes.xp);
	getch();

	Timer frame = {clock(), 200, 0};
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
		usleep(10000);
	}
}

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

void handleGameplayInput(char input)
{
}

#endif