#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../globals.h"

void writeRow(char *path, char *entry)
{
	FILE *handle = fopen(path, "a");
	fprintf(handle, entry);
	fclose(handle);
}

void getUser(char *path, char *username, char *row)
{
	FILE *handle = fopen(userPath, "r");

	if (handle == NULL)
	{
		puts("null");
		return;
	}

	if (strcmp(username, "admin") == 0)
	{
		strcpy(row, "admin");
		return;
	}

	char rowBuffer[150];
	while (fgets(rowBuffer, 150, handle) != NULL)
	{
		if (strlen(rowBuffer) <= 0)
			continue;
		char user[50];
		char pass[50];
		int money;
		char favFilms[100];
		sscanf(rowBuffer, "%[^#]#%[^#]#%d#%[^\n]\n", user, pass, &money, favFilms);
		if (strcmp(user, username) == 0)
		{
			strcpy(row, rowBuffer);
			return;
		}
	}

	strcpy(row, "");

	fclose(handle);
}

#endif