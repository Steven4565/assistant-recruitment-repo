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

#include "menus/mainMenu.h"

#include "globals.c"
#include "globals.h"

// PROTOTYPES

void render();

bool endGame = false;
void startEventLoop(void (*gameLoop)())
{
	Timer frame = {clock(), 20, 0};
	Timer enemy = {clock(), 4000, 0};
	while (!endGame)
	{
		getTimerInterval(&frame);
		getTimerInterval(&enemy);

		// MAIN LOOP
		runEvent(&frame, gameLoop);

		// EMIT EVENTS
		emitEvent(&enemy, &(events.onEnemyEmitted));

		// TODO: optimize delay with usleep
	}
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
	render(currentStage);
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

int main()
{
	menuLoop();
	// startEventLoop(&gameLoop); // this is for starting the main event
}