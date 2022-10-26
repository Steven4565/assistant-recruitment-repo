#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <stdio.h>
#include <conio.h>
#include "../utils/inputUtils.h"
#include "../utils/printUtils.h"

void handleNewGameLoopInput(int index, int arrLength, bool *runNewGame)
{
	// TODO: load user
	// TODO: startLobbyLoop();
	if (index == arrLength)
	{
		clrscr();
		*runNewGame = false;
	}
}

void newGameLoop()
{
	bool runNewGame = true;
	int index = 0;

	// TODO: get players array here
	char *arr[] = {"steven", "steven2", "steven 3"};
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printMenu(index, arr, arrLength);

	while (runNewGame)
	{
		clrscr();
		printMenu(index, arr, arrLength);
		char input = getch();
		if (getMenuScrollInput(input, &index, 0, arrLength) == -1)
		{
			handleNewGameLoopInput(index, arrLength, &runNewGame);
		}
	}
}

#endif