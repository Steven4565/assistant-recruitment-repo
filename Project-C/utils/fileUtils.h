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

	FILE *handle = fopen(filePath, "r");
	for (int i = 0; i < height; i++)
	{
		char str[60];
		fgets(str, 60, handle);
		for (int j = 0; j < width + 1; j++)
		{
			if (str[j] != '\n' && str[j] != '\0')
			{
				sprite->sprite[i][j] = str[j];
			}
			else
			{
				sprite->sprite[i][j] = ' ';
			}
		}
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
	// getch();

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

void sortLeaderboard()
{
	FILE *handle = fopen("./database/score.dat", "r");
	char name[100][50];
	int score[100];
	int count = 0;
	while (fscanf(handle, "%[^#]#%d\n", &name[count], &score[count]) != EOF)
	{
		count++;
	}

	if (DEBUG)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%-15s | %d\n", name[i], score[i]);
		}
		getch();
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i; j < count - 1; j++)
		{
			if (score[j] < score[j + 1])
			{
				// swap entries
				char temp[50];
				strcpy(temp, name[j]);
				int tempScore = score[j];

				strcpy(name[j], name[j + 1]);
				score[j] = score[j + 1];

				strcpy(name[j + 1], temp);
				score[j + 1] = tempScore;
			}
		}
	}

	if (DEBUG)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%-15s | %d\n", name[i], score[i]);
		}
		getch();
	}

	fclose(handle);

	// Rewrite to sorted list
	handle = fopen("./database/score.dat", "w");
	for (int i = 0; i < count; i++)
	{
		fprintf(handle, "%s#%d\n", name[i], score[i]);
	}

	fclose(handle);
}

void getLeaderboard()
{
	clrscr();

	FILE *handle = fopen("./database/score.dat", "r");
	char name[50];
	int score;
	printf("%-15s | %s\n", "Name", "Score");
	while (fscanf(handle, "%[^#]#%d\n", &name, &score) != EOF)
	{
		printf("%-15s | %d\n", name, score);
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