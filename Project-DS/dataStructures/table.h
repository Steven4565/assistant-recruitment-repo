#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "./entry.h"

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

void deleteTableRow(struct Table *table, struct Row *row)
{
	// free all entries of that row first
	deleteEntries(row->entryHead);

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

#endif