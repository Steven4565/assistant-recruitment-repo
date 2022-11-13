#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"
#include "../dataStructures/hashTable.h"

struct User
{
	char name[50];
	char pass[50];
	int money;
	char favFilms[150];
};

int getHash(char *code)
{
	unsigned long long hash = 5381;
	int size = strlen(code);
	int c;
	while (c = *code++)
	{
		hash = ((hash << 5) + hash) + c;
	}
	return hash % 9999;
}

void parseUser(struct User *user, char *row)
{
	sscanf(row, "%[^#]#%[^#]#%d#%[^\n]\n", user->name, user->pass, &(user->money), user->favFilms);
}

#endif