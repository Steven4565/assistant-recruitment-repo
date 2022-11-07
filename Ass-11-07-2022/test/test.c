#include <stdio.h>
#include <malloc.h>

struct Node
{
	int value;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *newNode(int num)
{
	struct Node *new = malloc(sizeof(struct Node));
	new->next = NULL;
	new->value = num;

	return new;
}

void pushHead(int num)
{
	struct Node *new = newNode(num);

	if (head == NULL)
	{
		head = tail = new;
	}
	else
	{
		new->next = head;
		head = new;
	}
}

void pushTail(int num)
{
	struct Node *new = newNode(num);

	if (head == NULL)
	{
		head = tail = new;
	}
	else
	{
		tail->next = new;
		tail = new;
	}
}

void popTail()
{
	if (head == NULL)
	{
		return;
	}
	else if (head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		struct Node *cur = head;

		while (cur->next != tail)
		{
			cur = cur->next;
		}

		free(tail);
		tail = cur;
		tail->next = NULL;
	}
}

void popMid(int query)
{
	if (head == NULL)
	{
		return;
	}
	else if (head == tail && head->value == query)
	{
		head = tail = NULL;
	}
	else
	{
		struct Node *cur = head;
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

void popHead()
{
	if (head == NULL)
	{
		return;
	}
	else if (head == tail)
	{
		free(head);
		head = tail = NULL;
	}

	struct Node *cur = head;
	head = head->next;
	free(cur);
}

void printList()
{
	struct Node *cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	puts("");
}

int main()
{
	pushHead(1);
	pushHead(2);
	pushHead(3);

	printList();

	return 0;
}