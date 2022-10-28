#ifndef LOAD_GAME_H
#define LOAD_GAME_H

#include <stdio.h>
#include <conio.h>
#include "../utils/inputUtils.h"
#include "../utils/printUtils.h"
#include "../utils/fileUtils.h"
#include "../menus/lobby.h"
#include "../globals.h"

void startNewGame(int index, bool *runLoadGameMenu)
{
	loadUser(playerEntries[index]);

	lobbyLoop();

	// Exit
	clrscr();
	*runLoadGameMenu = false;

	// TODO: update to database
}

void loadGameLoop()
{
	bool runLoadGameMenu = true;
	int index = 0;

	char *arr[playerEntryCount];
	for (int i = 0; i < playerEntryCount; i++)
	{
		arr[i] = playerEntries[i].name;
	}

	printMenu(index, arr, playerEntryCount);

	while (runLoadGameMenu)
	{
		clrscr();
		printMenu(index, arr, playerEntryCount);
		char input = getch();
		if (getMenuScrollInput(input, &index, 0, playerEntryCount) == -1)
		{
			startNewGame(index, &runLoadGameMenu);
		}
	}
}

#endif