#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdlib.h>
#include <stdio.h>

void writeRow(char *path, char delim, char *entry)
{
	FILE *handle = fopen(path, "a");

	fclose(handle);
}

void writeRows(char *path)
{
	FILE *handle = fopen(path, "a");

	fclose(handle);
}

void rewriteFile()
{
	FILE *handle = fopen("./database/player.dat", "w");

	fclose(handle);
}

void getRow()
{
	FILE *handle = fopen("./database/player.dat", "r");

	fclose(handle);
}

void getRows()
{
	FILE *handle = fopen("./database/player.dat", "r");

	fclose(handle);
}

void getEntries()
{
	FILE *handle = fopen("./database/player.dat", "r");

	fclose(handle);
}

#endif