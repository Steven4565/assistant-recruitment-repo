#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
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

struct FilmData
{
	char name[50];
	char desc[50];
	int price;
	int duration;
	char genres[150];
};

struct FilmData *newFilmData(char *name, char *desc, int price, int duration, char *genres)
{
	struct FilmData *created = (struct FilmData *)malloc(sizeof(struct FilmData));
	strcpy(created->name, name);
	strcpy(created->desc, desc);
	strcpy(created->genres, genres);
	created->price = price;
	created->duration = duration;
	return created;
}

int getHash(char *code)
{
	unsigned long long hash = 5381;
	int size = strlen(code);
	int c;
	while (c = *code++)
	{
		hash = ((hash << 5) + hash) + c;
	}
	return hash % 99;
}

void parseUser(struct User *user, char *row)
{
	sscanf(row, "%[^#]#%[^#]#%d#%[^\n]\n", user->name, user->pass, &(user->money), user->favFilms);
}

#endif