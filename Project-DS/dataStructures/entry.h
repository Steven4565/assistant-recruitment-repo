#ifndef ENTRY_H
#define ENTRY_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "table.h"

struct Entry
{
	int num;
	char *str;
	bool isInt;
	struct Entry *next;
	struct Entry *prev;
};

struct Row
{
	struct Entry *entryHead;
	struct Entry *entryTail;
	struct Row *next;
	struct Row *prev;
};

struct Entry *newEntryInt(int num)
{
	struct Entry *created = (struct Entry *)malloc(sizeof(struct Entry));
	created->isInt = true;
	created->num = num;
	created->next = NULL;
	created->prev = NULL;
	return created;
}

struct Row *newRow()
{
	struct Row *created = (struct Row *)malloc(sizeof(struct Row));
	created->entryHead = created->entryTail = NULL;
	created->next = created->prev = NULL;
	return created;
}

void pushRowTail(struct Row *row, struct Entry *entry)
{
	if (row->entryHead == NULL)
	{
		row->entryHead = row->entryTail = entry;
		return;
	}

	struct Entry *newEntry = entry;
	struct Entry *lastEntry = row->entryTail;
	lastEntry->next = newEntry;
	newEntry->prev = lastEntry;

	row->entryTail = newEntry;
}

struct Entry *newEntryStr(char *str)
{
	struct Entry *created = (struct Entry *)malloc(sizeof(struct Entry));
	created->isInt = false;
	created->str = str;
	created->next = NULL;
	created->prev = NULL;
	return created;
}

struct Entry *getEntry(struct Row *row, int index)
{
	int count = 0;
	struct Entry *cur = row->entryHead;
	while (cur != NULL)
	{
		if (count == index)
		{
			return cur;
		}
		cur = cur->next;
		count++;
	}

	return NULL;
}

void deleteEntries(struct Entry *head)
{
	struct Entry *cur = head;
	while (cur != NULL)
	{
		struct Entry *nextEntry = cur->next;
		free(cur);
		cur = nextEntry;
	}
}

void deleteRow(struct Row *row)
{
	deleteEntries(row->entryHead);
	free(row);
}

void printEntry(struct Entry *entry)
{
	if (entry->isInt)
	{
		printf("%d ", entry->num);
	}
	else
	{
		printf("%s ", entry->str);
	}
}

void printRow(struct Row *row)
{
	struct Entry *cur = row->entryHead;

	while (cur != NULL)
	{
		printEntry(cur);
		cur = cur->next;
	}

	puts("");
}

bool checkInRow(struct Row *row, char *query)
{
	struct Entry *cur = row->entryHead;
	while (cur != NULL)
	{
		if (!cur->isInt && strcmp(query, cur->str) == 0)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}

#endif