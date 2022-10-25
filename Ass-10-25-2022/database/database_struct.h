#ifndef DATABASE_STRUCT_H
#define DATABASE_STRUCT_H

typedef struct Entry
{
	char *stockName;
	char *stockCode;
	char *stockLabel;
	long long stockPrice;
} Entry;

#endif