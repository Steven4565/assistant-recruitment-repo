#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#include "config.h"

#include "utils/printUtils.h"
#include "utils/inputUtils.h"
#include "utils/eventTimer.h"

#include "events/eventStruct.h"
#include "events/events.c"
#include "events/events.h"
#include "events/handlers/enemyHandler.h"

bool endGame = false;

void startEventLoop(void (*mainLoop)())
{
	Timer frame = {clock(), 20, 0};
	Timer enemy = {clock(), 4000, 0};
	while (!endGame)
	{
		frame.msec = (clock() - frame.before) * 1000 / CLOCKS_PER_SEC;
		enemy.msec = (clock() - enemy.before) * 1000 / CLOCKS_PER_SEC;

		// MAIN LOOP
		if (frame.msec >= frame.delay)
		{
			frame.before = clock();

			// Run main event here
			mainLoop();
		}

		// EMIT EVENTS
		emitEvent(&enemy, &(events.onEnemyEmitted));

		// TODO: optimize delay with usleep
	}
}

void mainLoop()
{
	// clear screen
	clrscr();

	// get input
	char input = getInput();

	// handle events
	handleEnemy();

	// render
	printf("input: %c", input);
}

void init()
{
}

int main()
{
	init();
	startEventLoop(&mainLoop);
}