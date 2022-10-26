#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <conio.h>
#include <stdio.h>

char getInput()
{
	if (kbhit())
	{
		return getch();
	}
	else
	{
		return ' ';
	}
}

#endif