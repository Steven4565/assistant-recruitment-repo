#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "../utils/gameUtils.h"
#include "../globals.h"
#include "../globals.c"

#define SIZE 9999

struct HashEntry
{
	char name[100];
	int age;
	int weight;
	char gender[10];
	char code[30];
	struct HashEntry *next;
};

struct HashEntry *newHashNode(char *name, int age, int weight, char *gender, char *code)
{
	struct HashEntry *created = (struct HashEntry *)malloc(sizeof(struct HashEntry));
	strcpy(created->name, name);
	strcpy(created->code, code);
	strcpy(created->gender, gender);
	created->age = age;
	created->weight = weight;
	created->next = NULL;
	return created;
}

void pushHashTable(struct HashEntry **table, char *name, int age, int weight, char *gender, char *code)
{
	int key = getHash(code);
	if (table[key] == NULL)
	{
		table[key] = newHashNode(name, age, weight, gender, code);
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

	struct HashEntry *created = newHashNode(name, age, weight, gender, code);
	struct HashEntry *prev = cur;
	prev->next = created;
	cur = created;
}

void popHashTable(struct HashEntry **table, char *code)
{
	int key = getHash(code);
	if (table[key] == NULL)
	{
		return;
	}

	if (strcmp(table[key]->code, code) == 0)
	{
		struct HashEntry *temp = table[key];
		table[key] = table[key]->next;
		free(temp);
		temp = NULL;
	}
	else
	{
		struct HashEntry *cur = table[key];
		while (cur->next != NULL && strcmp(cur->next->code, code) != 0)
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
	for (int i = 0; i < SIZE; i++)
	{
		struct HashEntry *cur = table[i];
		while (cur != NULL)
		{
			printf("| %-25s | %-5d | %-7d | %-10s | %-15s |\n", cur->name, cur->age, cur->weight, cur->gender, cur->code);
			cur = cur->next;
		}
	}
}

#endif