#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void writeRow(char *path, char *entry)
{
	FILE *handle = fopen(path, "a");
	fprintf(handle, entry);
	fclose(handle);
}

// void rewriteFile()
// {
// 	FILE *handle = fopen("./database/player.dat", "w");

// 	fclose(handle);
// }

// void getRow()
// {
// 	FILE *handle = fopen("./database/player.dat", "r");

// 	fclose(handle);
// }

// void getRows()
// {
// 	FILE *handle = fopen("./database/player.dat", "r");

// 	fclose(handle);
// }

// void getEntries()
// {
// 	FILE *handle = fopen("./database/player.dat", "r");

// 	fclose(handle);
// }

void getUser(char *path, char *username, char *row)
{
	FILE *handle = fopen("./database/users.txt", "r");

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