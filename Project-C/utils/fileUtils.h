#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "../structs.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

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

#endif