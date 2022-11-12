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

#include "../globals.h"

bool searchFilmPage()
{
    char inputBuffer;
    char queryBuffer[50];
    while (true)
    {
        clrscr();
        printf("Search >> ");
        printf("%s\n", queryBuffer);
        printf("Results:\n");
        // TODO: print result here
        inputBuffer = getch();
        if (inputBuffer == '0')
        {
            break;
        }
        else if (inputBuffer == '\r')
        {
            // TODO: handle results here
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