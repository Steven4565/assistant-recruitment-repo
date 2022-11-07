#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <malloc.h>

struct Node
{
	int value;
	struct Node *next;
};

struct LinkedList
{
	struct Node *head;
	struct Node *tail;
};

void initList(struct LinkedList *list)
{
	list->head = NULL;
	list->tail = NULL;
}

struct Node *newNode(int num)
{
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->next = NULL;
	new->value = num;

	return new;
}

void pushHead(struct LinkedList *list, int num)
{
	struct Node *new = newNode(num);

	if (list->head == NULL)
	{
		list->head = list->tail = new;
	}
	else
	{
		new->next = list->head;
		list->head = new;
	}
}

void pushTail(struct LinkedList *list, int num)
{
	struct Node *new = newNode(num);

	if (list->head == NULL)
	{
		list->head = list->tail = new;
	}
	else
	{
		list->tail->next = new;
		list->tail = new;
	}
}

void popTail(struct LinkedList *list)
{
	if (list->head == NULL)
	{
		return;
	}
	else if (list->head == list->tail)
	{
		free(list->head);
		list->head = list->tail = NULL;
	}
	else
	{
		struct Node *cur = list->head;

		while (cur->next != list->tail)
		{
			cur = cur->next;
		}

		free(list->tail);
		list->tail = cur;
		list->tail->next = NULL;
	}
}

void popMid(struct LinkedList *list, int query)
{
	if (list->head == NULL)
	{
		return;
	}
	else if (list->head == list->tail && list->head->value == query)
	{
		list->head = list->tail = NULL;
	}
	else
	{
		struct Node *cur = list->head;
		while (cur->next != NULL && cur->next->value != query)
		{
			cur = cur->next;
		}

		if (cur->next == NULL)
		{
			return;
		}

		struct Node *toDelete = cur->next;
		cur->next = cur->next->next;
		free(toDelete);
	}
}

void popHead(struct LinkedList *list)
{
	if (list->head == NULL)
	{
		return;
	}
	else if (list->head == list->tail)
	{
		free(list->head);
		list->head = list->tail = NULL;
	}

	struct Node *cur = list->head;
	list->head = list->head->next;
	free(cur);
}

void replaceVal(struct LinkedList *list, int query, int target)
{
	if (list->head == NULL)
	{
		return;
	}
	else if (list->head->value == query)
	{
		list->head->value = target;
	}
	else
	{
		struct Node *cur = list->head;
		while (cur->next != NULL && cur->value != query)
		{
			cur = cur->next;
		}

		if (cur->value == query)
		{
			cur->value = target;
		}
	}
}

void printList(struct LinkedList *list)
{
	struct Node *cur = list->head;
	while (cur != NULL)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	puts("");
}

#endif