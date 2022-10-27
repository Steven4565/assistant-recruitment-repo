#ifndef LOAD_GAME_H
#define LOAD_GAME_H

#include <time.h>
#include <stdio.h>
#include "../utils/eventTimer.h"
#include "../events/eventStruct.h"
#include "../events/events.c"
#include "../events/events.h"
#include "../globals.h"
#include "../globals.c"
#include "../utils/printUtils.h"
#include "../utils/inputUtils.h"
#include "../events/handlers/enemyHandler.h"

void startEventLoop(void (*gameLoop)())
{
	bool endGame = false;
	Timer frame = {clock(), 20, 0};
	Timer enemy = {clock(), 4000, 0};
	while (!endGame)
	{
		setTimerInterval(&frame);
		setTimerInterval(&enemy);

		// MAIN LOOP
		runEvent(&frame, gameLoop);

		// EMIT EVENTS
		emitEvent(&enemy, &(events.onEnemyEmitted));

		// TODO: optimize delay with usleep
	}
}

void render()
{
}

void gameLoop()
{
	// clear screen
	clrscr();

	// get input
	char input = getKbdInput();

	// handle events
	handleEnemy();

	// render
	render();
}

#endif