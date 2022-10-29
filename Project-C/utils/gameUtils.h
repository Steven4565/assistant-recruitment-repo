
#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdbool.h>
#include "../structs.h"
#include "../globals.h"

bool checkCoordInNode(Node node, int x, int y)
{
	if (x >= node.pos.x && x <= node.pos.x + node.w - 1 && y >= node.pos.y && y <= node.pos.y + node.h - 1)
	{
		return true;
	}

	return false;
}

char getBoardChar(int x, int y)
{
	if (checkCoordInNode(game.currentPlayer.playerNode, x, y))
	{
		// return player char here
		return space1.sprite[y - game.currentPlayer.playerNode.pos.y][x - game.currentPlayer.playerNode.pos.x];
	}
	// if is
	// 	spaceship return spaceship char

	// 			if is enemy return enemy char

	// 			if is bullet return bullet char

	// 			return board char
	return board.sprite[y][x];
}

bool checkNodeCollision(Node node1, Node node2)
{
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