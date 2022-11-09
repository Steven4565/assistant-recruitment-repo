#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int value;
};

struct Stack
{
    struct Node *head;
    struct Node *cur;
};

struct Node *newNode(int value)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->next = NULL;
    new->value = value;

    return new;
}

struct Stack *newStack()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->head = NULL;
    stack->cur = NULL;
    return stack;
}

void push(struct Stack *stack, int value)
{
    struct Node *new = newNode(value);
    if (stack->head == NULL)
    {
        stack->head = new;
        return;
    }

    stack->cur->next = new;
}

int main()
{

    struct Stack *stack = newStack();

    return 0;
}