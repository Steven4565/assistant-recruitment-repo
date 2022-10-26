#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <stdio.h>
#include <conio.h>
#include "../utils/inputUtils.h"
#include "../utils/printUtils.h"

void printMenu(int index, const char **strArr)
{
}

void handleNewGameLoopInput(int index, bool *runMenu)
{
	switch (index)
	{
	case 0:
		printString("Input your new name: ");
		char name[100];
		getLine(name);
		// TODO: input to database
		// TODO: start lobby
		puts("Press enter to continue");
		getch();
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		*runMenu = false;
		puts("Exitting...");
		getch();
		break;
	}
}

void newGameLoop()
{
	bool runNewGame = true;
	int index = 0;

	// TODO: get players array here
	const char *arr[] = {"steven", "steven2"};
	printMenu(index, arr);

	while (runNewGame)
	{
		clrscr();
		printMenu(index, arr);
		char input = getch();
		if (getMenuScrollInput(input, &index, 0, 4) == -1)
		{
			// handleNewGameLoopInput(index, &runMenu);
		}
	}
}

#endif