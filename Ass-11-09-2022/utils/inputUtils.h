#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "outputUtils.h"
#include "validators.h"

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

bool getInputRange(char **menus, int menusLength, int min, int max, bool withZero, int *input)
{
	do
	{
		(withZero ? printMenusWith0(menus, menusLength) : printMenus(menus, menusLength));
		scanf("%d%*c", input);
	} while ((*input) < min || (*input) > max);
}

bool getInputInt(char *message, bool (*validator)(int), int *input)
{
	do
	{
		char temp[50];
		do
		{
			printf("%s: ", message);
			scanf("%[^\n]%*c", temp);

		} while (!intValidator(temp));
		*input = atoi(temp);

	} while (!validator(*input));
}

#endif