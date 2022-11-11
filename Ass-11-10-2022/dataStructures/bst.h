#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

#include "./entry.h"

struct BstNode
{
	struct Row *data;
	char *key;
	struct BstNode *left;
	struct BstNode *right;
};

struct Bst
{
	struct BstNode *head;
};

struct Bst *newBst()
{
	struct Bst *created = (struct Bst *)malloc(sizeof(struct Bst));
	created->head = NULL;
	return created;
}

struct BstNode *newBstNode(char *key, struct Row *data)
{
	struct BstNode *created = (struct BstNode *)malloc(sizeof(struct BstNode));
	created->key = key;
	created->data = data;
	created->left = NULL;
	created->right = NULL;
	return created;
}

struct BstNode *insertBstRoot(struct BstNode *root, char *key, struct Row *data)
{
	if (root == NULL)
	{
		return newBstNode(key, data);
	}

	int res = strcmp(root->key, key);

	switch (res)
	{
	case -1:
	{
		root->left = insertBstRoot(root->left, key, data);
		break;
	}
	case 1:
	{
		root->right = insertBstRoot(root->right, key, data);
		break;
	}
	case 0:
	{
		puts("Key has already existed");
		return root;
		break;
	}
	}

	return root;
}

void insertBst(struct Bst *tree, char *key, struct Row *data)
{
	tree->head = insertBstRoot(tree->head, key, data);
}

void printBstInfix(struct BstNode *parent)
{
	if (parent == NULL)
		return;
	printRow(parent->data);
	printBstInfix(parent->left);
	printBstInfix(parent->right);
}

struct BstNode *maxChildNode(struct BstNode *root)
{
	struct BstNode *cur = root;
	while (true)
	{
		if (cur->right == NULL)
		{
			return cur;
		}
		cur = cur->right;
	}
}

struct BstNode *deleteBstRoot(struct BstNode *root, char *key)
{
	if (root == NULL)
	{
		return root;
	}

	int res = strcmp(root->key, key);
	switch (res)
	{
	case -1:
	{
		root->left = deleteBstRoot(root->left, key);
		return root;
	}
	case 1:
	{
		root->right = deleteBstRoot(root->right, key);
		return root;
	}
	}

	// Case root has the same key
	if (root->left == NULL)
	{
		struct BstNode *temp = root->right;
		deleteRow(root->data);
		free(root);
		return temp;
	}

	if (root->right == NULL)
	{
		struct BstNode *temp = root->left;
		deleteRow(root->data);
		free(root);
		return temp;
	}

	struct BstNode *replaceCandidate = maxChildNode(root->left);
	// Replace the data instead because we have no reference of the left & right pointer of the node being replaced
	deleteRow(root->data);
	root->data = replaceCandidate->data;
	root->key = replaceCandidate->key;

	root->left = deleteBstRoot(root->left, replaceCandidate->key);

	return root;
}

void deleteBst(struct Bst *tree, char *key)
{
	tree->head = deleteBstRoot(tree->head, key);
}

#endif