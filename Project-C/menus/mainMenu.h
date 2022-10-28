#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <stdio.h>
#include <conio.h>
#include "../utils/inputUtils.h"
#include "../utils/printUtils.h"
#include "newGame.h"
#include "loadGame.h"

void printControls()
{
	clrscr();
	puts("\tWelcome to the game!");
	puts("");
	puts("\tBasic Movement");
	puts("\t'w' - Move Up");
	puts("\t'a' - Move Left");
	puts("\t's' - Move Down");
	puts("\t'd' - Move Right");
	puts("\t");
	puts("\tLobby Arena");
	puts("\t'SPACE' - Intersect");
	puts("\t'y' - Talk");
	puts("\t'o' - Open Backpack");
	puts("\t");
	puts("\tGame Arena");
	puts("\t'SPACE' - Shoot");
	puts("\t'r' - Reload");
	puts("\t'f' - Skill");
	puts("\t'1' - Use Potion");
	puts("\t'2' - Use Max Potion");
	puts("\t'3' - Use Energy");
	puts("\t'4' - Use Max Energy");
	puts("\t'g' - Use Bomb");
	puts("\t");
	puts("\tBack to menu ? [press enter]");
	getch();
}

void printTutorial()
{
	clrscr();
	puts("\tSpace Invader");
	puts("");
	puts("\tThe object of the game is, basically, to shoot the invaders with your shooter");
	puts("\twhile avoiding their shots and preventing an invasion  Amassing a high score is a further");
	puts("\tobjective and one that must be prioritised against your continued survival.");
	puts("\t");
	puts("\tThere is no time limit,");
	puts("\texcept for the fact that if you do not shoot them all before they reach");
	puts("\tthe bottom of the screen the game ends.");
	puts("\t");
	puts("\tCredit : Steven Christian");
	puts("\t");
	puts("\tBack to menu ? [press enter]");
	getch();
}

void handleMenuLoopInput(int index, bool *runMenu)
{
	switch (index)
	{
	case 0:
		printString("Input your new name: ");
		char name[100];
		getLine(name);

		int index = insertUser(name, 0, 0, 1, 100, 50, 1, 1);
		loadUser(playerEntries[index]);
		puts(currentPlayer.name);

		bool _; // I'm too lazy to make the last parameter optional
		startNewGame(index, &_);
		break;
	case 1:
		loadGameLoop();
		break;
	case 2:
		printControls();
		break;
	case 3:
		printTutorial();
		break;
	case 4:
		*runMenu = false;
		clrscr();
		puts("Exited program\nPress any key to continue...\n");
		getch();
		break;
	}
}

void menuLoop()
{
	bool runMenu = true;
	int index = 0;
	char *options[] = {"NEW GAME", "LOAD GAME", "CONTROLS", "HOW TO PLAY"};
	printMenu(index, options, 4);

	while (runMenu)
	{
		clrscr();
		printMenu(index, options, 4);
		char input = getch();
		if (getMenuScrollInput(input, &index, 0, 4) == -1)
		{
			handleMenuLoopInput(index, &runMenu);
		}
	}
}
#endif