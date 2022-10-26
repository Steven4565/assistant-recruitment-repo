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

#include "globals.c"
#include "globals.h"

bool endGame = false;

void startEventLoop(void (*mainLoop)())
{
	Timer frame = {clock(), 20, 0};
	Timer enemy = {clock(), 4000, 0};
	while (!endGame)
	{
		getTimerInterval(&frame);
		getTimerInterval(&enemy);

		// MAIN LOOP
		runEvent(&frame, mainLoop);

		// EMIT EVENTS
		emitEvent(&enemy, &(events.onEnemyEmitted));

		// TODO: optimize delay with usleep
	}
}

void render()
{
	switch (currentStage)
	{
	case mainMenu:
		/* code */
		break;

	default:
		break;
	}
}

void mainLoop()
{
	// clear screen
	clrscr();

	// get input
	char input = getKbdInput();

	// handle events
	handleEnemy();

	// render
	render(currentStage);
}

int main()
{
	// startEventLoop(&mainLoop); // this is for starting the main event
}