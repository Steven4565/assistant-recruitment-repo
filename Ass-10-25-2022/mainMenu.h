#ifndef MAINMENU_H
#define MAINMENU_H

#include <stdio.h>
#include "utils.h"

// Main Menu

void printMenu()
{
	puts("1. Insert stock");
	puts("2. View all stock");
	puts("3. Delete stock");
	puts("4. Exit program");
	printf(">> ");
}

void mainMenuInput(long long *input)
{
	do
	{
		printMenu();
		getInputInt(input);
	} while (!validateInputRange(1, 4, *input));
}

#endif