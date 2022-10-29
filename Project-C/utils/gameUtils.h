
#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../structs.h"
#include "../globals.h"

// PROTOTYPES
bool checkCoordInNode(Node node, int x, int y);
int checkEnemyInCoords(Vector2D coord);

// PRINT UTILS
char getBoardChar(int x, int y)
{
	Vector2D coords = {x, y};

	if (checkCoordInNode(game.currentPlayer.playerNode, x, y))
	{
		return space1.sprite[y - game.currentPlayer.playerNode.pos.y][x - game.currentPlayer.playerNode.pos.x];
	}

	// return enemy char
	int result = checkEnemyInCoords(coords);
	if (result != -1)
	{
		Enemy enemy = game.enemies[result];
		Sprite enemySprite;
		switch (enemy.damage)
		{
		case 1:
			enemySprite = enemy1;
			break;
		case 2:
			enemySprite = enemy2;
			break;
		case 3:
			enemySprite = enemy3;
			break;
		}

		Vector2D enemyVec = enemy.enemy.pos;
		return enemySprite.sprite[y - enemyVec.y][x - enemyVec.x];
	}

	// return bullet char
	for (int i = 0; i < game.bulletCount; i++)
	{
		if (checkCoordInNode(game.bullets[i].bullet, x, y))
		{
			return '*';
		}
	}
	return board.sprite[y][x];
}

// COLLISSION DETECTORS

bool checkCoordInNode(Node node, int x, int y)
{
	if (x >= node.pos.x && x <= node.pos.x + node.w - 1 && y >= node.pos.y && y <= node.pos.y + node.h - 1)
	{
		return true;
	}

	return false;
}

bool checkNodeCollision(Node node1, Node node2)
{
}

bool checkBoardCollision(Sprite board, int x, int y)
{
	if (board.sprite[y][x] != ' ')
	{
		return false;
	}

	return true;
}

bool checkShops(Vector2D shop, Vector2D player)
{
	int x = player.x;
	int y = player.y;
	if ((x == shop.x + 1 && y == shop.y) || (x == shop.x - 1 && y == shop.y) || (x == shop.x && y == shop.y + 1) || (x == shop.x && y == shop.y - 1))
	{
		return true;
	}

	return false;
}

bool boardNodeCollided(Sprite board, Node node)
{
	for (int i = 0; i < node.h; i++)
	{
		for (int j = 0; j < node.w; j++)
		{
			if (board.sprite[i + node.pos.y][j + node.pos.x] != ' ')
				return true;
		}
	}

	return false;
}

// returns -1 if none is found
int checkEnemyInCoords(Vector2D coord)
{
	int x = coord.x;
	int y = coord.y;
	for (int i = 0; i < game.enemyCount; i++)
	{
		if (checkCoordInNode(game.enemies[i].enemy, x, y))
		{
			return i;
		}
	}
	return -1;
}

// MOVEMENT

void handleMoveVector(char inputChar, Vector2D *inputVector)
{
	switch (inputChar)
	{
	case 'w':
		inputVector->x = 0;
		inputVector->y = -1;
		return;
	case 'a':
		inputVector->x = -1;
		inputVector->y = 0;
		return;
	case 's':
		inputVector->x = 0;
		inputVector->y = 1;
		return;
	case 'd':
		inputVector->x = 1;
		inputVector->y = 0;
		return;
	default:
		return;
	}
}

void movePlayerNode(Sprite board, Node *playerNode, Vector2D moveVector)
{
	// check collision in node
	for (int i = 0; i < playerNode->h; i++)
	{
		for (int j = 0; j < playerNode->w; j++)
		{
			Node temp = {.pos.x = playerNode->pos.x + moveVector.x,
									 .pos.y = playerNode->pos.y + moveVector.y,
									 .h = playerNode->h,
									 .w = playerNode->w};
			if (!boardNodeCollided(board, temp))
			{
				playerNode->pos.x += moveVector.x;
				playerNode->pos.y += moveVector.y;
				return;
			}
		}
	}
}

// GAMEPLAY

void shootBullet(Vector2D startPos, Vector2D direction, int bulletOwner, int bulletDamage)
{
	if (bulletOwner == bulletOwner_player && game.currentPlayer.attributes.bullets <= 0)
	{
		return;
	}

	Bullet temp = {.bullet.pos = startPos,
								 .bullet.h = 1,
								 .bullet.w = 1,
								 .direction = direction,
								 .bulletOwner = bulletOwner,
								 .bulletDamage = bulletDamage};
	game.bullets[game.bulletCount] = temp;
	game.bulletCount++;

	// only if the player is shooting
	if (bulletOwner == bulletOwner_player)
		game.currentPlayer.attributes.bullets--;
}

void swapBullet(Bullet *bullet1, Bullet *bullet2)
{
	Bullet temp = *bullet1;
	*bullet1 = *bullet2;
	*bullet2 = temp;
}

void deleteBullet(int i)
{
	for (int i = i; i < game.bulletCount - 1; i++)
	{
		swapBullet(&game.bullets[i], &game.bullets[i + 1]);
	}

	game.bulletCount--;
}

void swapEnemy(Enemy *enemy1, Enemy *enemy2)
{
	Enemy temp = *enemy1;
	*enemy1 = *enemy2;
	*enemy2 = temp;
}

void deleteEnemy(int i)
{
	for (int i = i; i < game.enemyCount - 1; i++)
	{
		swapEnemy(&game.enemies[i], &game.enemies[i + 1]);
	}

	game.enemyCount--;
}

void addEnemy(Enemy enemy)
{
	game.enemies[game.enemyCount] = enemy;
	game.enemyCount++;
}

// OTHER UTILS

int getRandom(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

#endif