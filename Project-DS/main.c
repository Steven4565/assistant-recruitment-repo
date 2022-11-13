#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <malloc.h>

#include "utils/utils.h"
#include "utils/validators.h"
#include "utils/inputUtils.h"
#include "utils/dataLoader.h"

#include "menus/mainPage.h"

#include "dataStructures/table.h"
#include "dataStructures/hashtable.h"

#include "globals.h"

void init()
{
    srand(time(NULL));
    filmsList = newTrieNode();
    loadGenresLL();
    loadFilms();
    loadFavorites();
}

void testTrie()
{
    int namesLength = 0;
    char names[4][50];
    queryTrieKeys(filmsList, "violet", names, &namesLength);
    for (int i = 0; i < namesLength; i++)
    {
        puts(names[i]);
    }

    struct FilmData *data = queryTrieData(filmsList, names[1]);
    chooseFilmPage(names, namesLength);
    getEnter();
}

void testHashTable()
{
    pushHashTable(userFavoritesTable, "steven", "angel beats");
    pushHashTable(userFavoritesTable, "steveasdfn", "angel beats, asdfadsf");
    pushHashTable(userFavoritesTable, "nevets", "angel beats, asdf");
    printHashTable(userFavoritesTable);
}

void testFavPage()
{
    char *testRow = "test1,test2,test3,test54";
    strcpy(currentUser.favFilms, testRow);

    printf("count :%d", getFilmsCount(currentUser.favFilms));
    while (favoriteFilmPage())
        ;
    getEnter();
}

int main()
{

    init();

    // testTrie();
    // testHashTable();
    // testFavPage();

    while (mainPage())
        ;

    return 0;
}