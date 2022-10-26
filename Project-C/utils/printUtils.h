#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <stdio.h>

void clrscr()
{
	printf("\e[1;1H\e[2J");
}

void printInt(char *str, int value)
{
	printf("%s: %d\n", str, value);
}

void printString(char *str)
{
	printf("%s", str);
}

void printMenu(int selection, char **strArr, int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		printf("%s\t%c\n", strArr[i], (selection == i ? '<' : ' '));
	}
	printf("Exit\t\t%c\n", (selection == arrLength ? '<' : ' '));
}

#endif