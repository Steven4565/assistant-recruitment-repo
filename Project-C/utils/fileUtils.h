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
	sprite->sprite = malloc((height));
	for (int i = 0; i < height; i++)
	{
		(sprite->sprite)[i] = malloc(width + 1);
	}

	FILE *file = fopen(filePath, "r");
	for (int i = 0; i < height; i++)
	{
		char buffer[100];
		fscanf(file, "%[^\n]\n", buffer);
		char *spriteRow = sprite->sprite[i];
		puts(buffer);
		printInt("i", i);
		strcpy(spriteRow, buffer);
		// printInt("size", sizeof(spriteRow));
	}

	// fclose(file);
}

#endif