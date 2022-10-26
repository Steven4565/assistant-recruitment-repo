#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <conio.h>
#include <stdio.h>
#include <stdbool.h>

char getKbdInput()
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

/*
	ret vals:
		-1: enter
		-2: other char
	else: index value after moved
 */
int getMenuScrollInput(char input, int *index, int min, int max)
{
	switch (input)
	{
	case 'w':
		if (*index > min)
		{
			(*index)--;
		}
		return *index;
	case 's':
		if (*index < max)
		{
			(*index)++;
		}
		return *index;
	case '\r':
		return -1;
	}

	return -2;
}

#endif