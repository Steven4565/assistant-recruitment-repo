#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

void getCode(char *name, int age, int weight, char *gender, char *code)
{
	char randomS[5];
	itoa(getRandom(1, 100), randomS, 10);
	strcat(code, randomS);

	for (char *p = strtok(name, " "); p != NULL; p = strtok(NULL, " "))
	{
		char firstLetter = toupper(p[0]);
		strncat(code, &firstLetter, 1);
	}

	char genderChar = toupper(gender[0]);
	strncat(code, &genderChar, 1);

	int lastNum = (genderChar * age) / 4;
	char lastNumS[10];
	itoa(lastNum, lastNumS, 10);
	strcat(code, lastNumS);

	printf("code: %s\n", code);
}

int getHash(char *code)
{
	int size = strlen(code);
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += code[i];
		sum %= 9999;
	}
	return sum;
}

#endif