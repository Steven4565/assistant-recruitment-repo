#ifndef DATABASE_H
#define DATABASE_H

#include "database_struct.h"
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "database.c"
#include "../utils.h"

extern int dbLen;
extern Entry database[100];

int checkIfCodeExists(char *code)
{
	for (int i = 0; i < dbLen; i++)
	{
		// printf("length: %d\n", strlen(code));
		// printf("length2: %d\n", strlen(database[i].stockCode));
		// printf("compare: %d\n", compareString(code, database[i].stockCode, strlen(code)));
		if (compareString(code, database[i].stockCode, strlen(code)))
		{
			return i;
		}
	}
	return -1;
}

void swapEntries(int index1, int index2)
{
	Entry temp = {database[index1].stockName,
								database[index1].stockCode,
								database[index1].stockLabel,
								database[index1].stockPrice};

	char stockName[1000], stockCode[10], stockLabel[50];
	long long stockPrice;
	strcpy(stockName, database[index1].stockName);
	strcpy(stockCode, database[index1].stockCode);
	strcpy(stockLabel, database[index1].stockLabel);
	stockPrice = database[index1].stockPrice;

	strcpy(database[index1].stockName, database[index2].stockName);
	strcpy(database[index1].stockCode, database[index2].stockCode);
	strcpy(database[index1].stockLabel, database[index2].stockLabel);
	database[index1].stockPrice = database[index2].stockPrice;

	strcpy(database[index2].stockName, stockName);
	strcpy(database[index2].stockCode, stockCode);
	strcpy(database[index2].stockLabel, stockLabel);
	database[index2].stockPrice = stockPrice;
}

void moveEntriesForward(int index)
{
	for (int i = index; i < (dbLen - 1); i++)
	{
		swapEntries(index, index + 1);
	}
}

#endif
