#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

struct bsdNode
{
	int val;
	struct bsdNode *left;
	struct bsdNode *right;
};

struct bsdNode *newBsdNode(int val)
{
	struct bsdNode *created = (struct bsdNode *)malloc(sizeof(struct bsdNode));
	created->right = NULL;
	created->left = NULL;
	created->val = val;

	return created;
}

struct bsdNode *pushBsd(struct bsdNode *root, int val)
{
	if (root == NULL)
	{
		return newBsdNode(val);
	}

	if (val < root->val)
	{
		// move left
		root->left = pushBsd(root->left, val);
	}
	else if (val > root->val)
	{
		// move right
		root->right = pushBsd(root->right, val);
	}
	else
	{
		printf("duplicate value error");
	}

	return root;
}

void searchBsd(struct bsdNode *root, int val)
{
	if (root == NULL)
	{
		return;
	}

	if (root->val == val)
	{
		printf("value found");
		return;
	}

	if (val < root->val)
	{
		searchBsd(root->left, val);
	}
	else if (val > root->val)
	{
		searchBsd(root->right, val);
	}
}

void infix(struct bsdNode *cur)
{
	if (cur != NULL)
	{
		printf("%d\n", cur->val);
		infix(cur->left);
		infix(cur->right);
	}
}

void prefix(struct bsdNode *cur)
{
	if (cur != NULL)
	{
		infix(cur->left);
		printf("%d\n", cur->val);
		infix(cur->right);
	}
}

void suffix(struct bsdNode *cur)
{
	if (cur != NULL)
	{
		infix(cur->left);
		infix(cur->right);
		printf("%d\n", cur->val);
	}
}

int main()
{
	struct bsdNode *root = NULL;
	root = pushBsd(root, 40);
	pushBsd(root, 30);
	pushBsd(root, 60);

	searchBsd(root, 450);

	return 0;
}