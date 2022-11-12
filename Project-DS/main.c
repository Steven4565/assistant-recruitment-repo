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

#include "menus/mainPage.h"

#include "dataStructures/table.h"
#include "dataStructures/hashtable.h"

#include "globals.h"

void init()
{
    srand(time(NULL));
    pushRowTail(&genres, newEntryStr("romance"));
    pushRowTail(&genres, newEntryStr("drama"));
    pushRowTail(&genres, newEntryStr("action"));
    pushRowTail(&genres, newEntryStr("mecha"));
    pushRowTail(&genres, newEntryStr("horror"));
    pushRowTail(&genres, newEntryStr("fantasy"));
    pushRowTail(&genres, newEntryStr("comedy"));
    pushRowTail(&genres, newEntryStr("adventure"));
}

void test()
{
    char row[150];
    getUser(userPath, "irkimuzak", row);
    usernameLoginValidator(";asjfalkjsdf");
}

int main()
{

    // test();

    init();

    while (mainPage())
        ;

    return 0;
}