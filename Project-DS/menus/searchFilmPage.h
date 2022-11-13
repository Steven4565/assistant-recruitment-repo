#ifndef SEARCH_FILM_PAGE
#define SEARCH_FILM_PAGE

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

bool chooseFilmPage(char names[4][50], int namesSize)
{
    clrscr();
    char *options[5] = {"Return"};
    for (int i = 0; i < namesSize; i++)
    {
        options[i + 1] = names[i];
    }

    int inputBuffer;
    getInputRange(options, namesSize + 1, 0, namesSize, true, &inputBuffer);
    if (inputBuffer == 0)
    {
        return false;
    }

    puts(options[inputBuffer]);
    getEnter();
    // TODO: go to film details, pass in the name as the parameter

    return true;
}

bool searchFilmPage()
{
    char inputBuffer;
    char queryBuffer[50] = "";
    while (true)
    {
        clrscr();
        printf("Search >> ");
        printf("%s\n", queryBuffer);
        printf("Results:\n");
        int namesSize = 0;
        char names[4][50];
        queryTrieKeys(filmsList, queryBuffer, names, &namesSize);
        for (int i = 0; i < namesSize; i++)
        {
            printf("%d. %s\n", i + 1, names[i]);
        }

        inputBuffer = getch();
        if (inputBuffer == '0')
        {
            break;
        }
        else if (inputBuffer == '\r')
        {
            while (chooseFilmPage(names, namesSize))
                ;
            break;
        }
        else if (inputBuffer == '\b')
        {
            queryBuffer[strlen(queryBuffer) - 1] = '\0';
        }
        else if (inputBuffer == ' ' || isalnum(inputBuffer))
        {
            strncat(queryBuffer, &inputBuffer, 1);
        }
    }
    return false;
}

#endif