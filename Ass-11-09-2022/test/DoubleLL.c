#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    struct Node *next;
    int val;
};

struct DoubleLL
{
    struct Node *head;
    struct Node *tail;
};

struct Node *newNode(int value)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->next = NULL;
    new->prev = NULL;
    new->val = value;

    return new;
}

struct DoubleLL *newLL()
{
    struct DoubleLL *list = malloc(sizeof(struct DoubleLL));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void pushHead(struct DoubleLL *list, int value)
{
    if (list->head == NULL)
    {
        list->head = list->tail = newNode(value);
        return;
    }
    struct Node *new = newNode(value);
    new->next = list->head;
    list->head->prev = new;
    list->head = new;
}

void pushTail(struct DoubleLL *list, int value)
{
    struct Node *new = newNode(value);
    if (list->head == NULL)
    {
        list->head = list->tail = new;
        return;
    }

    list->tail->next = new;
    new->prev = list->tail;
    list->tail = new;
}

void pushMid(struct DoubleLL *list, int value)
{

    if (list->head == NULL)
    {
        struct Node *new = newNode(value);
        list->head = list->tail = new;
        return;
    }
    if (list->head->val > value)
    {
        pushHead(list, value);
    }
    else if (list->tail->val < value)
    {
        pushTail(list, value);
    }
    else
    {
        struct Node *cur = list->head;
        while (cur)
        {
            if (value < cur->val)
            {
                printf("test: %d\n", cur->val);
                break;
            }
            cur = cur->next;
        }

        // set the next value to the new node;
        struct Node *new = newNode(value);
        struct Node *back = cur->prev;
        struct Node *front = cur;

        new->next = front;
        new->prev = back;

        back->next = new;
        front->prev = new;
    }
}

struct Node *popHead(struct DoubleLL *list)
{
    if (list->head == NULL)
    {
        return NULL;
    }

    if (list->head == list->tail)
    {
        struct Node *temp = list->head;
        list->head = list->tail = NULL;
        return temp;
    }

    struct Node *temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    return temp;
}

struct Node *popTail(struct DoubleLL *list)
{
    if (list->head == NULL)
    {
        return NULL;
    }

    if (list->head == list->tail)
    {
        struct Node *temp = list->head;
        list->head = list->tail = NULL;
        return temp;
    }

    struct Node *temp = list->tail;
    temp->next = NULL;

    list->tail->prev = NULL;
    return temp;
}

struct Node *popMid(struct DoubleLL *list, int value)
{
    if (list->head == NULL)
    {
        return NULL;
    }

    if (list->head == list->tail)
    {
        struct Node *temp = list->head;
        list->head = list->tail = NULL;
        return temp;
    }

    struct Node *cur = list->head;
    while (cur)
    {
        if (cur->val == value)
        {
            break;
        }
        cur = cur->next;
    }

    struct Node *back = cur->prev;
    struct Node *front = cur->next;
    back->next = front;
    front->prev = back;

    return cur;
}

void printList(struct DoubleLL *list)
{
    struct Node *cur = list->head;
    while (cur != NULL)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}

int main()
{
    struct DoubleLL *list = newLL();

    pushTail(list, 10);
    pushTail(list, 11);
    pushTail(list, 13);
    pushTail(list, 14);
    pushMid(list, 12);

    printList(list);
    return 0;
}