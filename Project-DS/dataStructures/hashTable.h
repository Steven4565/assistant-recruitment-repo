#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "../utils/gameUtils.h"
#include "../globals.h"

#define HASH_TABLE_SIZE 99

struct HashEntry
{
	char name[50];
	char favFilms[200];
	struct HashEntry *next;
};

struct HashEntry *newHashNode(char *name, char *favFilms)
{
	struct HashEntry *created = (struct HashEntry *)malloc(sizeof(struct HashEntry));
	strcpy(created->name, name);
	strcpy(created->favFilms, favFilms);
	created->next = NULL;
	return created;
}

void pushHashTable(struct HashEntry **table, char *name, char *favFilms)
{
	int key = getHash(name);
	if (table[key] == NULL)
	{
		table[key] = newHashNode(name, favFilms);
		return;
	}

	struct HashEntry *cur = table[key];
	while (true)
	{
		if (cur->next == NULL)
		{
			break;
		}
		cur = cur->next;
	}

	struct HashEntry *created = newHashNode(name, favFilms);
	struct HashEntry *prev = cur;
	prev->next = created;
	cur = created;
}

void popHashTable(struct HashEntry **table, char *name)
{
	int key = getHash(name);
	if (table[key] == NULL)
	{
		return;
	}

	if (strcmp(table[key]->name, name) == 0)
	{
		struct HashEntry *temp = table[key];
		table[key] = table[key]->next;
		free(temp);
		temp = NULL;
	}
	else
	{
		struct HashEntry *cur = table[key];
		while (cur->next != NULL && strcmp(cur->next->name, name) != 0)
		{
			cur = cur->next;
		}

		if (cur->next == NULL)
			return;

		struct HashEntry *toBeDeleted = cur->next;

		if (cur->next->next != NULL)
		{
			cur->next = toBeDeleted->next;
		}
		else
		{
			cur->next = NULL;
		}

		free(toBeDeleted);
	}
}

void printHashTable(struct HashEntry **table)
{
	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		struct HashEntry *cur = table[i];
		while (cur != NULL)
		{
			printf("| %-35s | %-25s |\n", cur->name, cur->favFilms);
			cur = cur->next;
		}
	}
}

#endif