#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "outputUtils.h"

void getEnter()
{
	printf("Press enter to continue...\n");
	getchar();
	clrscr();
}

bool getInputString(char *message, bool (*validator)(char *), char *input)
{
	do
	{
		printf("%s: ", message);
		scanf("%[^\n]%*c", input);
	} while (!validator(input));
}

bool getInputRange(char **menus, int menusLength, int min, int max, int *input)
{
	do
	{
		printMenus(menus, menusLength);
		scanf("%d%*c", input);
	} while ((*input) < min || (*input) > max);
}

#endif