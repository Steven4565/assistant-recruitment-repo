
#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "config.h"

bool validateInputRange(int min, int max, int input)
{
	if (input >= min && input <= max)
	{
		return true;
	}
	return false;
}

bool validateInputMinMax(int min, int max, int input)
{
	if (input <= min && input >= max)
	{
		return true;
	}
	return false;
}

void getInputString(char *input)
{
	scanf("%[^\n]%*c", input);
}

void getInputInt(long long *input)
{
	scanf("%lld%*c", input);
}

int getRandom(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

void clearScreen()
{
	printf("\e[1;1H\e[2J");
}

void choose4Chars(char *input, char *output)
{
	char str[1000] = "";
	for (int i = 0; i < strlen(input); i++)
	{
		char char_ = toupper(input[i]);
		if (char_ >= 'A' && char_ <= 'Z')
			strncat(str, &char_, 1);
	}

	// generate random indices
	int length = strlen(str);
	int randChoice[4];
	for (int i = 0; i < 4; i++)
	{
		randChoice[i] = getRandom(0, length - i - 1);
		if (DEBUG)
			printf("rand: %d\n", randChoice[i]);
	}

	// select characters based on random indices
	for (int i = 0; i < 4; i++)
	{
		int nthChar = randChoice[i];
		int index = 0;
		for (int j = 0; j < length; j++)
		{

			if (index == nthChar && str[j] != '-')
			{
				strncat(output, &str[j], 1);
				str[j] = '-';
				break;
			}

			if (str[j] != '-')
			{
				index++;
			}
		}
	}

	// append random number
	int randomNum = getRandom(1, 100);
	char numStr[10];
	itoa(randomNum, numStr, 10);
	strcat(output, numStr);
}

bool compareString(char *str1, char *str2, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}

#endif