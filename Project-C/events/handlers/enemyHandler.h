#ifndef ENEMY_HANDLER_H
#define ENEMY_HANDLER_H

#include <stdio.h>
#include "../events.h"

void handleEnemy()
{
	if (events.onEnemyEmitted)
	{
		events.onEnemyEmitted = false;
		printf("enemy\n");
	}
}
#endif