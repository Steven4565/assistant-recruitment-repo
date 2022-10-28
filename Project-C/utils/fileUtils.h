#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "../structs.h"
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

	FILE *file = fopen(filePath, "r");
	for (int i = 0; i < height + 1; i++)
	{
		fscanf(file, "%[^\n]\n", sprite->sprite[i]);
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

	fclose(file);
}

void loadDatabase()
{
	FILE *handle = fopen("./database/score.dat", "r");
	char name[50];
	int money, xp, level, hp, armor;
	double energy;

	int index = 0;
	while (fscanf(handle, "%[^#]#%d#%d#%d#%d#%lf#%d\n", &name, &money, &xp, &level, &hp, &energy, &armor) != EOF)
	{
		// TODO: load to cache here
	}

	if (DEBUG)
	{
		puts("Press any key to continue");
		getch();
	}
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
}

#endif