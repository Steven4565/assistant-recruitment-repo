#ifndef OUTPUT_UTILS_H
#define OUTPUT_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void clrscr()
{
	printf("\e[1;1H\e[2J");
}

void printMenus(char **options, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d. ", i + 1);
		puts(options[i]);
	}
}

void printMenusWith0(char **options, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d. ", i);
		puts(options[i]);
	}
}

#endif