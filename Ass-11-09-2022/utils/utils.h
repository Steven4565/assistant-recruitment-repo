#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <ctype.h>

int getRandom(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

bool isNumber(char *str)
{
	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

#endif