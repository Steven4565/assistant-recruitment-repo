#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "../utils/gameUtils.h"

#define SIZE 99

struct HashNode
{
    char name[100];
    char favFilms[200];
    struct HashNode *next;
} * table[SIZE];

struct HashNode *newHashNode(char *name, char *favFilms)
{
    struct HashNode *created = (struct HashNode *)malloc(sizeof(struct HashNode));
    strcpy(created->name, name);
    strcpy(created->favFilms, favFilms);
    created->next = NULL;
}

void push(char *name, char *favFilms)
{
    int key = getHash(name);
    if (table[key] == NULL)
    {
        table[key] = newHashNode(name, favFilms);
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

    struct HashNode *created = newHashNode(name, favFilms);
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
            return;

        struct HashNode *toBeDeleted = cur->next;

        if (cur->next->next != NULL)
        {
            cur->next = toBeDeleted->next;
        }
        else
        {
            cur->next = NULL;
        }

        free(toBeDeleted);
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
            printf("name: %25s  |  value: %25s\n", cur->name, cur->favFilms);
            cur = cur->next;
        }
    }
}

int main()
{
    push("hello", 10);
    push("helol", 11);
    push("hoell", 12);
    push("ohell", 13);
    push("asdf", 100);
    // pop("hoell");

    printHashTable();

    return 0;
}