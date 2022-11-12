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

    while (menuPage())
        ;

    return 0;
}