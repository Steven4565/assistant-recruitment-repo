#ifndef TRIE_H
#define TRIE_H

#define CHILDREN_SIZE 27

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct FilmData
{
	char name[50];
	char desc[50];
	int price;
	int duration;
	int genres[150];
};

struct TrieNode
{
	struct TrieNode *children[CHILDREN_SIZE];
	bool isEndOfWord;
	struct FilmData *film;
};

int mapToIndex(char input)
{
	if (input == ' ')
	{
		return 26;
	}
	else
	{
		return input - 'a';
	}
}

char mapToChar(int input)
{
	if (input == 26)
	{
		return ' ';
	}
	else
	{
		return input + 'a';
	}
}

struct TrieNode *newTrieNode()
{
	struct TrieNode *created = (struct TrieNode *)malloc(sizeof(struct TrieNode));
	created->isEndOfWord = false;
	created->film = NULL;
	for (int i = 0; i < CHILDREN_SIZE; i++)
	{
		created->children[i] = NULL;
	}

	return created;
}

void insertTrie(struct TrieNode *root, char *key)
{
	struct TrieNode *cur = root;
	int length = strlen(key);
	for (int level = 0; level < length; level++)
	{
		int index = mapToIndex(key[level]);
		if (cur->children[index] == NULL)
		{
			cur->children[index] = newTrieNode();
		}
		cur = cur->children[index];
	}
	cur->isEndOfWord = true;
}

bool searchTrie(struct TrieNode *root, char *key)
{
	struct TrieNode *cur = root;
	int length = strlen(key);
	for (int level = 0; level < length; level++)
	{
		int index = mapToIndex(key[level]);
		if (cur->children[index] == NULL)
		{
			return false;
		}
		cur = cur->children[index];
	}

	return cur->isEndOfWord;
}

bool trieNodeEmpty(struct TrieNode *node)
{
	if (node == NULL)
	{
		return true;
	}
	for (int i = 0; i < CHILDREN_SIZE; i++)
	{
		if (node->children[i] != NULL)
		{
			return false;
		}
	}
	return true;
}

struct TrieNode *deleteTrieRoot(struct TrieNode *root, char *key, int depth)
{
	if (root == NULL)
	{
		return NULL;
	}

	int length = strlen(key);
	if (depth == length)
	{
		root->isEndOfWord = false;
	}
	else
	{
		int index = mapToIndex(key[depth]);
		root->children[index] = deleteTrieRoot(root->children[index], key, depth + 1);
	}

	if (trieNodeEmpty(root) && !root->isEndOfWord)
	{
		free(root);
		root = NULL;
	}
	return root;
}

void deleteTrie(struct TrieNode *root, char *key)
{
	root = deleteTrieRoot(root, key, 0);
}

void printTrieRoot(struct TrieNode *root, char *query, char *buffer, int level, int *printCount)
{
	if (root->isEndOfWord && *printCount > 0)
	{
		buffer[level] = '\0';
		printf("%s%s\n", query, buffer);
		*printCount -= 1;
	}

	for (int i = 0; i < CHILDREN_SIZE; i++)
	{
		if (root->children[i] != NULL && *printCount > 0)
		{
			buffer[level] = mapToChar(i);
			printTrieRoot(root->children[i], query, buffer, level + 1, printCount);
		}
	}
}

void printTrie(struct TrieNode *root, char *key, int maxPrints)
{
	int length = strlen(key);
	struct TrieNode *cur = root;
	for (int i = 0; i < length && cur != NULL; i++)
	{
		int index = mapToIndex(key[i]);
		cur = cur->children[index];
	}

	if (trieNodeEmpty(cur))
	{
		puts("No films found");
	}
	else
	{
		char buffer[50];
		printTrieRoot(cur, key, buffer, 0, &maxPrints);
	}
}

#endif