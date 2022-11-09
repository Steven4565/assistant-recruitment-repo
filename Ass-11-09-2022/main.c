#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "utils/utils.h"
#include "utils/validators.h"
#include "utils/inputUtils.h"

#include "menus/mainPage.h"

#include "dataStructures/table.h"
#include "dataStructures/hashTable.h"

#include "globals.h"

void init()
{
    srand(time(NULL));
}

void test()
{
    pushHashTable(hashTable, "steven", 18, 42, "male", "asdfasdf");
    pushHashTable(hashTable, "melvion", 16, 4, "male", "asdf1");
    pushHashTable(hashTable, "phi", 48, 23, "male", "asdf23");
    pushHashTable(hashTable, "nathan", 19, 43, "male", "asdf3");
    pushHashTable(hashTable, "dani", 11, 46, "male", "asdf4");
    pushHashTable(hashTable, "shanie", 12, 87, "female", "asdf6");

    popHashTable(hashTable, "asdf4");
    printHashTable(hashTable);
    getEnter();
}

int main()
{
    // test();

    init();

    while (menuPage())
        ;

    return 0;
}