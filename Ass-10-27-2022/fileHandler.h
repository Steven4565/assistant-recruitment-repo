#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void getFileEntries(char *nameArr[], char *numberArr[], char *addressArr[], int *length)
{
	FILE *file = fopen("file.txt", "r");
	if (file == NULL)
	{
		puts("error opening file");
		return;
	}

	int index = 0;
	// while (fscanf(file, "%[^#]#%[^#]#%[^\n]\n", nameArr[index], numberArr[index], addressArr[index]) != EOF)
	// {
	// 	index++;
	// }

	char name[1000];
	char num[1000];
	char addr[1000];
	while (fscanf(file, "%[^#]#%[^#]#%[^\n]\n", name, num, addr) != EOF)
	{
		nameArr[index] = malloc(strlen(name) + 1);
		numberArr[index] = malloc(strlen(num) + 1);
		addressArr[index] = malloc(strlen(addr) + 1);
		strcpy(nameArr[index], name);
		strcpy(numberArr[index], num);
		strcpy(addressArr[index], addr);
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