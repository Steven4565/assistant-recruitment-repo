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
#include "dataStructures/bst.h"
#include "dataStructures/entry.h"

#include "globals.h"

void init()
{
    srand(time(NULL));
}

void test()
{
    char *keys[] = {"1111", "3333", "2222", "4444", "5555"};
    struct Bst *bst = newBst();

    for (int i = 0; i < 5; i++)
    {
        struct Row *row = newRow();
        pushRowTail(row, newEntryInt(i));

        insertBst(bst, keys[i], row);
    }

    struct Row *row = newRow();
    pushRowTail(row, newEntryInt(1122));
    insertBst(bst, "1122", row);

    deleteBst(bst, "1122");
    printBstInfix(bst->head);
}

int main()
{
    init();

    test();

    // while (menuPage())
    //     ;

    return 0;
}