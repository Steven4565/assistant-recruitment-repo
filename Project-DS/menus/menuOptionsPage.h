#ifndef MENU_OPTIONS_PAGE
#define MENU_OPTIONS_PAGE

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

#include "./searchFilmPage.h"
#include "./favoriteFilmPage.h"

void uploadFilm()
{
    clrscr();
    char name[50];
    char desc[200];
    int price;
    int duration;
    char genres[150];

    getInputString("Input name", nameValidator, name);
    getInputString("Input description", nameValidator, desc);
    getInputInt("Input borrow per minute price", positiveValidator, &price);
    getInputInt("Input film duration", positiveValidator, &duration);
    getInputString("Input genres (separated by commas only)", genreValidator, genres);

    // TODO: push to trie, update file
}

void returnFilm()
{
    clrscr();
}

bool menuOptionsPage()
{
    clrscr();
    puts("filMZ");
    puts("===========");

    char *menus[] = {
        "Logout",
        "Search Film",
        "Upload Film",
        "Return Film",
        "Favorited Film"};
    int input;
    getInputRange(menus, 4, 0, 4, true, &input);

    // Exit Program
    if (input == 0)
        return false;

    switch (input)
    {
    case 1:
        while (searchFilmPage())
            ;
        break;
    case 2:
        uploadFilm();
        break;
    case 3:
        returnFilm();
    case 4:
        while (favoriteFilmPage())
            ;
        break;
    }

    return true;
}

#endif