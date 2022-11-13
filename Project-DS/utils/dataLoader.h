#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../dataStructures/entry.h"
#include "../dataStructures/hashTable.h"
#include "../dataStructures/trie.h"
#include "../dataStructures/table.h"

#include "../globals.h"

void loadFilms()
{
	FILE *handle = fopen("./database/films.txt", "r");

	char rowBuffer[150];
	while (fgets(rowBuffer, 150, handle) != NULL)
	{
		if (strlen(rowBuffer) <= 0)
			continue;
		char name[50];
		char desc[200];
		int price;
		int duration;
		char genres[150];
		sscanf(rowBuffer, "%[^#]#%[^#]#%d#%d#%[^\n]\n", name, desc, &price, &duration, genres);
		insertTrie(filmsList, name);
		pushHashTable(filmsDatabase, name, desc, price, duration, genres);
	}

	fclose(handle);
}

void loadGenresLL()
{
	pushRowTail(&genres, newEntryStr("romance"));
	pushRowTail(&genres, newEntryStr("drama"));
	pushRowTail(&genres, newEntryStr("action"));
	pushRowTail(&genres, newEntryStr("mecha"));
	pushRowTail(&genres, newEntryStr("horror"));
	pushRowTail(&genres, newEntryStr("fantasy"));
	pushRowTail(&genres, newEntryStr("comedy"));
	pushRowTail(&genres, newEntryStr("adventure"));
}

#endif