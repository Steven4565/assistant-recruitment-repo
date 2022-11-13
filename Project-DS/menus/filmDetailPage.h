#ifndef FILM_DETAIL_PAGE
#define FILM_DETAIL_PAGE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "../utils/inputUtils.h"
#include "../utils/outputUtils.h"
#include "../utils/validators.h"
#include "../utils/fileUtils.h"
#include "../utils/utils.h"
#include "../utils/gameUtils.h"

#include "../dataStructures/trie.h"

#include "../globals.h"

void borrowFilm(char *filmName)
{
}

void removeFavorited(char *filmName)
{
}

bool filmDetailsPage(char *filmName)
{
	clrscr();
	struct FilmData *filmData = queryTrieData(filmsList, filmName);
	puts("Film Details:");

	printf("%-25s : %s\n", "Name", filmData->name);
	printf("%-25s : %s\n", "Description", filmData->desc);
	printf("%-25s : %s\n", "Genres", filmData->genres);
	printf("%-25s : %d\n", "Price per minute", filmData->price);
	printf("%-25s : %d minute(s)\n", "Duration", filmData->duration);
	// printf("%-25s : %s\n", "Uploader", filmData->);

	char *options[] = {"Return",
										 "Borrow film",
										 "Remove from favorited film"};
	int inputBuffer;
	printf("\nMenus: \n");
	getInputRange(options, 3, 0, 2, true, &inputBuffer);
	if (inputBuffer == 0)
		return false;

	switch (inputBuffer)
	{
	case 1:
		borrowFilm(filmName);
		break;
	case 2:
		removeFavorited(filmName);
		break;
	}
}

#endif