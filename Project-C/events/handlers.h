#ifndef HANDLERS_H
#define HANDLERS_H

#include <stdio.h>
#include <time.h>
#include "../globals.h"
#include "../utils/gameUtils.h"

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

// CALLBACKS

void handleMessageReset()
{
	if (!events.resetMessageFlag)
		return;

	events.resetMessageFlag = false;
	deactivateTimer(&events.resetMessageFlag);
	game.message = "";
}

void handleMoveBullets()
{
	for (int i = 0; i < game.bulletCount; i++)
	{
		Vector2D moveVector = game.bullets[i].direction;
		int x = game.bullets[i].bullet.pos.x + moveVector.x;
		int y = game.bullets[i].bullet.pos.y + moveVector.y;
		Vector2D destVector = {.x = x, .y = y};

		Node destNode = {.pos = destVector, .h = 1, .w = 1};
		// check if collides with wall
		if (boardNodeCollided(board, destNode))
		{
			deleteBullet(i);
			return;
		}

		switch (game.bullets[i].bulletOwner)
		{
		case bulletOwner_enemy:
			if (checkCoordInNode(game.currentPlayer.playerNode, x, y))
			{
				int *hp = &game.currentPlayer.attributes.hp;
				*hp -= game.bullets[i].bulletDamage;
				if (*hp < 0)
				{
					game.gameOver = true;
				}
			}
			break;
		case bulletOwner_player:
		{
			int result = checkEnemyInCoords(destVector);
			if (result != -1)
			{
				deleteBullet(i);
				deleteEnemy(result);
				game.currentPlayer.attributes.score += 10;
			}
			break;
		}
		default:
			break;
		}

		game.bullets[i].bullet.pos = destVector;
	}
}

void handleGenerateEnemies()
{
}

void handleReload()
{
	if (!events.reloadFlag)
		return;

	game.currentPlayer.attributes.bullets = 10;

	events.reloadFlag = false;
	deactivateTimer(&game.timers.reloadTimer);
}

void handleMoveEnemies()
{
}
#endif