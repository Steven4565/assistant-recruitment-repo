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
	deactivateTimer(&game.timers.resetMessageTimer);
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
				deleteBullet(i);
				return;
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
				return;
			}
			break;
		}
		}

		game.bullets[i].bullet.pos = destVector;
	}
}

void handleReload()
{
	if (!events.reloadFlag)
		return;

	game.currentPlayer.attributes.bullets = 10;

	events.reloadFlag = false;
	deactivateTimer(&game.timers.reloadTimer);
}

void handleGenerateEnemies()
{
	if (!events.generateEnemyFlag)
		return;

	for (int i = 0; i < game.enemyCount; i++)
	{
		if (game.enemies[i].enemy.pos.y >= 21) // Enemy hits bottom border
		{
			game.gameOver = true;
			return;
		}
		game.enemies[i].enemy.pos.y += 1;
	}

	// get random spawn location (top left corner)
	Vector2D baseSpawn = {.x = getRandom(4, 49 - 2 - 11 + 1), .y = 0};
	Vector2D moveVector = {.x = (getRandom(1, 2) == 1 ? 1 : -1), .y = 0};

	for (int i = 0; i < 3; i++)
	{
		// add enemy
		Vector2D enemySpawnPos = {.x = baseSpawn.x + i * 4, .y = baseSpawn.y};
		Node enemyNode = {.pos = enemySpawnPos, .w = 3, .h = 1};
		Enemy enemy = {.enemy = enemyNode, .direction = moveVector, .damage = getRandom(1, 3) * 10, .index = game.enemyIndex};
		addEnemy(enemy);
	}

	events.generateEnemyFlag = false;
}

void handleMoveEnemies()
{
	if (!events.moveEnemyFlag)
		return;

	for (int i = 0; i < game.enemyCount; i++)
	{
		Vector2D enemyPos = game.enemies[i].enemy.pos;
		Vector2D enemyMoveVec = game.enemies[i].direction;

		Vector2D dest = {enemyPos.x + enemyMoveVec.x, enemyPos.y + enemyMoveVec.y};
		game.enemies[i].enemy.pos = dest;

		if (enemyMoveVec.x == -1)
		{
			game.enemies[i].direction.x = 1;
		}
		else
		{
			game.enemies[i].direction.x = -1;
		}
	}

	events.moveEnemyFlag = false;
}

void handleEnemyShoot()
{
	if (!events.enemyShootFlag)
		return;

	// shoot bullets from enemies
	for (int i = 0; i < game.enemyCount; i++)
	{
		Vector2D startPos = game.enemies[i].enemy.pos;
		startPos.x++; // 1 unit away from the corner left

		Vector2D direction = {.x = 0, .y = 1};
		shootBullet(startPos, direction, bulletOwner_enemy, game.enemies[i].damage);
	}

	game.timers.enemyShootTimer.delay = 3000 + getRandom(0, 1000);
	events.enemyShootFlag = false;
}

#endif