#ifndef INSERT_H
#define INSERT_H

#include "../utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../config.h"
#include "../database/api/insertEntry.h"
#include "../database/database_struct.h"

// Prototypes
long long generateIndex(int price);
long long adjustIndex(int price);

// Functions

void inputStockName(char *name)
{
	do
	{
		printf("Input the stock name[>= 4 char]: ");
		getInputString(name);
	} while (strlen(name) < 4);
}

void inputStockPrice(long long *price)
{
	do
	{
		printf("Input the stock price[>= 500]: ");
		getInputInt(price);
	} while (*price < 500);
}

void generateStockCode(char *stockCode, char *name)
{
	choose4Chars(name, stockCode);
	if (DEBUG)
		printf("code: %s\n", stockCode);
}

void getStockCode(char *stockCode, char *name)
{
	do
	{
		generateStockCode(stockCode, name);
	} while (checkIfCodeExists(stockCode) != -1);
}

void getStockLabel(char *stockLabel, long long price)
{
	int index = generateIndex(price);
	while (index > 8562)
	{
		index = adjustIndex(price);
	}

	char *label;

	if (index >= 5708)
	{
		label = "blue chip";
	}
	else if (index >= 2854)
	{
		label = "middle chip";
	}
	else
	{
		label = "small cap";
	}
	strcat(stockLabel, label);
}

long long generateIndex(int price)
{
	int random = getRandom(1, 100);
	return price * random;
}

long long adjustIndex(int price)
{
	int random = getRandom(1, 37);
	int random2 = getRandom(1, 100);
	return (price * random / 2) * random2;
}

void insertStock()
{
	char name[1001];
	long long price;
	inputStockName(name);
	inputStockPrice(&price);

	char stockCode[100];
	getStockCode(stockCode, name);

	char stockLabel[100] = "";
	getStockLabel(stockLabel, price);

	printf("Successfully added a new stock named %s with stock code %s\n", name, stockCode);
	if (DEBUG)
		printf("stock label: %s\n", stockLabel);

	insertEntry(name, stockCode, stockLabel, price);
	getchar();
}

#endif
