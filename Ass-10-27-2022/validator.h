#ifndef VALDATOR_H
#define VALDATOR_H

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "utils.h"

bool validateInt(int input, int min, int max)
{
	if (input >= min && input <= max)
	{
		return true;
	}

	return false;
}

//  012345, l=6
// "hellow"
//     "ow"
bool endsWith(char *str, int length, char *query, int queryLength)
{

	for (int i = length - queryLength; i < queryLength; i++)
	{
		if (str[i] != query[i - length + queryLength])
		{
			return false;
		}
	}
	return true;
}

bool isAllNumbers(char *str, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

#endif