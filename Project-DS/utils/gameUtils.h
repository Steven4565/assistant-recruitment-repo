#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

struct User
{
	char name[50];
	char pass[50];
	int money;
	char favFilms[150];
};

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

void parseUser(struct User *user, char *row)
{
	sscanf(row, "%[^#]#%[^#]#%d#%[^\n]\n", user->name, user->pass, &(user->money), user->favFilms);
}

#endif