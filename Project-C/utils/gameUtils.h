
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

void movePlayer(Sprite board, Vector2D *player, Vector2D input)
{
	// check for collission
	if (checkBoardCollision(board, player->x + input.x, player->y + input.y))
	{
		// if no collision, move player
		player->x += input.x;
		player->y += input.y;
	}
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

	// if (checkBoardCollision(board, ))
}

#endif