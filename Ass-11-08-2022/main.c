#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "utils/utils.h"
#include "utils/validators.h"
#include "utils/inputUtils.h"

#include "menus/mainPage.h"
#include "menus/adminPage.h"
#include "menus/clientPage.h"

#include "dataStructures/table.h"
// #include "dataStructures/queue.h"
// #include "dataStructures/stack.h"

#include "globals.h"

void init()
{
    g_dramaTable = newTable();
}

void test()
{

    struct Table *table = newTable();

    int n = 10;
    for (int i = 0; i < n; i++)
    {
        struct Row *row = newRow();

        for (int j = 0; j < n; j++)
        {
            if (j == 2)
            {
                pushRowTail(row, newEntryStr("entry"));
            }
            else if (j == 3)
            {
                pushRowTail(row, newEntryStr("anotherEntry"));
            }
            else
            {
                pushRowTail(row, newEntryInt(j + n * i));
            }
        }

        pushTableTail(table, row);
    }

    // test query
    struct Row *foundRow = searchRowInt(table, 1, 51);

    // test delete
    deleteRow(table, foundRow);

    // test update
    struct Row *foundRow2 = searchRowInt(table, 1, 61);
    foundRow2->entryHead->num = 999;

    // test print
    printTable(table);

    /*
    Table is a multidimentional double linked list

    Create drama table: row = newRow() -> pushRowTail(newData(value)) -> pushTableTail(table, row)
    Read drama table: printTable(table);
    Update drama table: search for row index with searchRowInt(table, 0, dramaIndex)
    Delete drama table: toBeDeleted = searchRowInt() -> deleteRow(toBeDeleted)
    */
}

int main()
{
    test();

    // init();

    // while (menuPage())
    //     ;

    return 0;
}