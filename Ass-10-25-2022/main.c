#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "utils.h"
#include "mainMenu.h"
#include "menus/view.h"
#include "menus/delete.h"
#include "menus/insert.h"
#include "config.h"
#include "database/database.h"
#include "database/database_struct.h"
#include "database/api/insertEntry.h"

bool programDoneRunning = false;

void Init()
{
	srand(time(NULL));
	if (DEBUG)
	{
		// insertEntry("test1", "ASDF12", "1", 1);
		// insertEntry("test2", "ASDF13", "2", 2);
		// insertEntry("test3", "ASDF14", "3", 3);
		// swapEntries(0, 1);
	}
}

void App()
{
	long long input;
	mainMenuInput(&input);

	switch (input)
	{
	case 1:
		insertStock();
		break;
	case 2:
		viewStock();
		break;
	case 3:
		deleteStock();
		break;
	case 4:
		programDoneRunning = true;
		printf("Program Exited Successfully\nPress enter to continue...");
		getchar();
		break;
	default:
		printf("Wrong input somehow :/");
		break;
	}
	clearScreen();
}

int main()
{
	Init();

	while (!programDoneRunning)
	{
		App();
	}

	return 0;
}