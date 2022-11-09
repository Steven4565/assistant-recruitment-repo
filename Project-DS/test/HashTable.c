#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "../utils/gameUtils.h"

#define SIZE 999

struct HashNode
{
    char name[100];
    int score;
    struct HashNode *next;
} * table[SIZE];

struct HashNode *newHashNode(char *name, int score)
{
    struct HashNode *created = (struct HashNode *)malloc(sizeof(struct HashNode));
    strcpy(created->name, name);
    created->score = score;
    created->next = NULL;
}

void push(char *name, int score)
{
    int key = getHash(name);
    if (table[key] == NULL)
    {
        table[key] = newHashNode(name, score);
        return;
    }

    struct HashNode *cur = table[key];
    while (true)
    {
        if (cur->next == NULL)
        {
            break;
        }
        cur = cur->next;
    }

    struct HashNode *created = newHashNode(name, score);
    struct HashNode *prev = cur;
    prev->next = created;
    cur = created;
}

void pop(char *name)
{
    int key = getHash(name);
    if (table[key] == NULL)
    {
        return;
    }

    if (strcmp(table[key]->name, name) == 0)
    {
        struct HashNode *temp = table[key];
        table[key] = table[key]->next;
        free(temp);
        temp = NULL;
    }
    else
    {
        struct HashNode *cur = table[key];
        while (cur->next != NULL && strcmp(cur->next->name, name) != 0)
        {
            cur = cur->next;
        }

        if (cur->next == NULL)
        {
            return;
        }

        struct HashNode *toBeDeleted = cur->next;
        cur->next = NULL;
        free(toBeDeleted);

        // move current node's next to deleted's next
    }
}

void printHashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        struct HashNode *cur = table[i];
        while (cur != NULL)
        {
            printf("i: %d  |  ", i);
            printf("name: %s  |  value: %d\n", cur->name, cur->score);
            cur = cur->next;
        }
    }
}

int main()
{
    push("hello", 10);
    push("helllo", 100);
    push("asdf", 100);
    pop("hello");

    printHashTable();

    return 0;
}