#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

struct Table
{
	struct Row *head;
	struct Row *tail;
};

struct Table *newTable()
{
	struct Table *table = (struct Table *)malloc(sizeof(struct Table));
	table->head = NULL;
	table->tail = NULL;
}

struct Row *newRow()
{
	struct Row *created = (struct Row *)malloc(sizeof(struct Row));
	created->entryHead = created->entryTail = NULL;
	created->next = created->prev = NULL;

	return created;
}

struct Entry *newEntryInt(int num)
{
	struct Entry *created = (struct Entry *)malloc(sizeof(struct Entry));
	created->isInt = true;
	created->num = num;
	created->next = NULL;
	created->prev = NULL;
	return created;
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

void pushTableTail(struct Table *table, struct Row *row)
{
	if (table->head == NULL)
	{
		table->head = table->tail = row;
		return;
	}

	struct Row *newRow = row;
	struct Row *lastRow = table->tail;
	lastRow->next = newRow;
	newRow->prev = lastRow;

	table->tail = newRow;
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

	printf("Row: ");
	while (cur != NULL)
	{
		printEntry(cur);
		cur = cur->next;
	}

	puts("");
}

void printTable(struct Table *table)
{
	struct Row *cur = table->head;

	puts("Table");
	while (cur != NULL)
	{
		printRow(cur);
		cur = cur->next;
	}
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

struct Row *searchRowInt(struct Table *table, int col, int query)
{
	struct Row *cur = table->head;
	while (cur != NULL)
	{
		if (getEntry(cur, col)->num == query)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

void deleteRow(struct Table *table, struct Row *row)
{
	// free all entries of that row first
	struct Entry *cur = row->entryHead;
	while (cur != NULL)
	{
		struct Entry *nextEntry = cur->next;
		free(cur);
		cur = nextEntry;
	}

	// free the row
	struct Row *back = row->prev;
	struct Row *front = row->next;

	if (row == table->head)
	{
		table->head = front;
		front->prev = NULL;
	}
	else if (row == table->tail)
	{
		table->tail = back;
		back->next = NULL;
	}
	else
	{
		back->next = front;
		front->prev = back;
	}

	free(row);
}

#endif