#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void getFileEntries(char nameArr[100][100], char numberArr[100][100], char addressArr[100][100], int *length)
{
	FILE *file = fopen("file.txt", "r");
	if (file == NULL)
	{
		puts("error opening file");
		return;
	}

	int index = 0;
	while (fscanf(file, "%[^#]#%[^#]#%[^\n]\n", &(nameArr[index]), &(numberArr[index]), &(addressArr[index])) != EOF)
	{
		index++;
	}
	*length = index;

	fclose(file);
}

void insertEntry(char *name, char *num, char *addr)
{
	FILE *file = fopen("file.txt", "a");
	if (file == NULL)
	{
		puts("error opening file");
		return;
	}

	// fwrite();

	fclose(file);
}

#endif