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
}

void test()
{
    int namesLength = 0;
    char names[4][50];
    queryTrieKeys(filmsList, "violet", names, &namesLength);
    for (int i = 0; i < namesLength; i++)
    {
        puts(names[i]);
    }

    struct FilmData *data = queryTrieData(filmsList, names[1], data);
    chooseFilmPage(names, namesLength);
    getEnter();
}

int main()
{

    init();

    // test();

    while (mainPage())
        ;

    return 0;
}