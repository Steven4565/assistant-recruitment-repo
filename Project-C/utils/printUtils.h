#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <stdio.h>

void clrscr()
{
	printf("\e[1;1H\e[2J");
}

#endif