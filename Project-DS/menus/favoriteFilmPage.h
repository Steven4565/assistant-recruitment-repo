#ifndef FAVORITE_FILM_PAGE
#define FAVORITE_FILM_PAGE

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

#include "../globals.h"

int getFilmsCount(char *favFilms)
{
	char strtokBuffer[200];
	strcpy(strtokBuffer, favFilms);

	char delim[2] = ",";
	char *token;

	token = strtok(strtokBuffer, delim);

	int favFilmsCount = 0;

	while (token != NULL)
	{
		token = strtok(NULL, delim);
		favFilmsCount++;
	}

	return favFilmsCount;
}

bool favoriteFilmPage()
{
	char strtokBuffer[200];

	char delim[2] = ",";
	char *token;

	if (currentUser.favFilms[0] == '-')
	{
		puts("User does not have any favorite films");
		getEnter();
		return false;
	}

	int favFilmsCount = getFilmsCount(currentUser.favFilms);

	int input;
	do
	{
		char temp[50];
		do
		{
			strcpy(strtokBuffer, currentUser.favFilms);
			token = strtok(strtokBuffer, delim);
			puts("0. Return");

			int i = 1;
			while (token != NULL)
			{
				printf("%d. ", i);
				puts(token);

				token = strtok(NULL, delim);
				i++;
			}
			scanf("%[^\n]%*c", temp);

		} while (!intValidator(temp));
		input = atoi(temp);

	} while (input < 0 || input > favFilmsCount);

	if (input == 0)
	{
		return false;
	}

	strcpy(strtokBuffer, currentUser.favFilms);
	token = strtok(strtokBuffer, delim);
	int i = 1;
	char newFavFilms[200];
	while (token != NULL)
	{
		if (input != i)
		{
			strcat(newFavFilms, token);
			strcat(newFavFilms, ",");
		}

		token = strtok(NULL, delim);
		i++;
	}
	newFavFilms[strlen(newFavFilms) - 1] = '\n'; // Replace trailing comma with newline

	strcpy(currentUser.favFilms, newFavFilms);
	// TODO: rewrite file here

	return true;
}

#endif