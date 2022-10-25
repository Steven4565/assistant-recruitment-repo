#ifndef INSERT_ENTRY_H
#define INSERT_ENTRY_H

#include "../database.h"
#include "../database_struct.h"
#include <string.h>
#include <stdio.h>

void insertEntry(char *stockName, char *stockCode, char *stockLabel, long long stockPrice)
{
	database[dbLen].stockName = malloc(strlen(stockName) + 2);
	database[dbLen].stockCode = malloc(strlen(stockCode) + 2);
	database[dbLen].stockLabel = malloc(strlen(stockLabel) + 2);

	strcpy(database[dbLen].stockName, stockName);
	strcpy(database[dbLen].stockCode, stockCode);
	strcpy(database[dbLen].stockLabel, stockLabel);
	database[dbLen].stockPrice = stockPrice;

	if (DEBUG)
	{
		printf("length: %d\n", strlen(database[dbLen].stockName));
		printf("string: %s\n", database[dbLen].stockName);
	}

	dbLen++;
}

#endif
