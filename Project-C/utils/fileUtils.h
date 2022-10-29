#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "../structs.h"
#include "../globals.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

void loadSprite(Sprite *sprite, char *filePath)
{
	int width = sprite->w;
	int height = sprite->h;

	if (DEBUG)
	{
		// printInt("width", width);
		// printInt("height", height);
	}

	FILE *handle = fopen(filePath, "r");
	for (int i = 0; i < height + 1; i++)
	{
		fscanf(handle, "%[^\n]\n", sprite->sprite[i]);
	}

	// check array by printing it out
	// puts("\nstring: ");
	// for (int i = 0; i < height + 1; i++)
	// {
	// 	for (int j = 0; j < width; j++)
	// 	{
	// 		printf("%c", sprite->sprite[i][j]);
	// 	}
	// 	// for (int j = 0; j < width; j++)
	// 	// {
	// 	// 	printf("%d", i);
	// 	// }
	// 	puts("");
	// }

	fclose(handle);
}

void loadDatabase()
{
	FILE *handle = fopen("./database/player.dat", "r");
	char name[50];
	int money, xp, level, hp, armor, damage;
	double energy;

	int index = 0;

	PlayerEntry *entry = &playerEntries[index];
	while (fscanf(handle, "%[^#]#%d#%d#%d#%d#%lf#%d#%d\n", name, &money, &xp, &level, &hp, &energy, &armor, &damage) != EOF)
	{
		strcpy(entry->name, name);
		entry->money = money;
		entry->xp = xp;
		entry->level = level;
		entry->hp = hp;
		// printInt("armor", hp);
		entry->energy = energy;
		entry->armor = armor;
		entry->damage = damage;
		index++;
		entry = &playerEntries[index];
	}

	playerEntryCount = index;

	if (DEBUG)
	{
		// printf("last index name: %d\n", playerEntries[index - 1].damage);
		// puts("Press any key to continue");
		// getch();
	}

	fclose(handle);
}

void getLeaderboard()
{
	clrscr();

	FILE *handle = fopen("./database/score.dat", "r");
	char name[50];
	int score;
	printf("Name | Score\n");
	while (fscanf(handle, "%[^#]#%d\n", &name, &score) != EOF)
	{
		printf("%s | %d\n", name, score);
	}
	puts("Press any key to continue");
	getch();

	fclose(handle);
}

int insertUser(char *name, int money, int xp, int level, int hp, double energy, int armor, int damage)
{
	PlayerEntry *entry = &playerEntries[playerEntryCount];
	strcpy(entry->name, name);
	entry->money = money;
	entry->xp = xp;
	entry->level = level;
	entry->hp = hp;
	entry->energy = energy;
	entry->armor = armor;
	entry->damage = damage;
	playerEntryCount++;

	FILE *handle = fopen("./database/player.dat", "a");
	fprintf(handle, "%s#%d#%d#%d#%d#%.0lf#%d#%d\n", name, money, xp, level, hp, energy, armor, damage);

	fclose(handle);

	return playerEntryCount - 1;
}

#endif