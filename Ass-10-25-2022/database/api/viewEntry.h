#ifndef VIEW_ENTRY_H
#define VIEW_ENTRY_H

#include "../database.h"
#include <stdio.h>
#include <string.h>

double viewEntry()
{
	if (dbLen == 0)
	{
		puts("No entries in database, consider inserting an entry");
		puts("Press enter to continue...");
		getchar();
		return 0.0;
	}

	double idx = 0;

	for (int i = 0; i < dbLen; i++)
	{
		printf("No: %d", i + 1);
		printf("\tName: %s\n", database[i].stockName);
		// if (DEBUG)
		// 	printf("length: %s\n", strlen(database[i].stockName));
		printf("\tCode: %s\n", database[i].stockCode);
		printf("\tLabel: %s\n", database[i].stockLabel);
		printf("\tPrice: %lld\n", database[i].stockPrice);
		puts("");
		idx += database[i].stockPrice;
	}

	idx = idx * 3 / 2 / dbLen;
	return idx;
}

#endif