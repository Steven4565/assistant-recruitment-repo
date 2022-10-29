#ifndef HANDLERS_H
#define HANDLERS_H

#include <stdio.h>
#include <time.h>

void handleEnemy()
{
	if (events.onEnemyEmitted)
	{
		events.onEnemyEmitted = false;
		printf("enemy\n");
		// TODO: move enemies here
	}
}

void handleMessageReset()
{
	if (events.onResetMessageEmitted)
	{
		events.onResetMessageEmitted = false;
		// deactivateTimer()
		game.message = "";
	}
}

void activateTimer(Timer *timer, int delay)
{
	timer->on = true;
	timer->before = clock();
	timer->delay = delay;
	timer->msec = 0;
}

void deactivateTimer(Timer *timer)
{
	timer->on = false;
}

void displayMessage(char *message, Timer *timer, int delay)
{
	game.message = message;
	activateTimer(timer, delay);
}

#endif