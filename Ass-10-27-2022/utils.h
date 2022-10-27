#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

void clrscr()
{
	printf("\e[1;1H\e[2J");
}

void printInt(int n)
{
	printf("%d", n);
}

void scanInt(int *n)
{
	scanf("%d%*c", n);
}

void printString(char *str)
{
	printf("%s", str);
}

void getLine(char *str)
{
	scanf("%[^\n]%*c", str);
}

#endif