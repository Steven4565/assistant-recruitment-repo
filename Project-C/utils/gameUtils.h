
#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdbool.h>
#include "../structs.h"
#include "../globals.h"

char getBoardChar(Vector2D position)
{
	// if is
	// 	spaceship return spaceship char

	// 			if is enemy return enemy char

	// 			if is bullet return bullet char

	// 			return board char
}

bool checkLobbyCollision(int x, int y)
{

	if (lobby.sprite[y][x] != ' ')
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

#endif