#ifndef BST_H
#define BST_H

#define CHILDREN_SIZE 27

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TrieNode
{
    struct TrieNode *children[CHILDREN_SIZE];
    bool isEndOfWord;
};

int mapToIndex(char input)
{
    if (input == ' ')
        return 26;
    else
        return input - 'a';
}

struct TrieNode *newTrieNode()
{
    struct TrieNode *created = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    created->isEndOfWord = false;
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
            buffer[level] = i + 'a';
            printTrieRoot(root->children[i], query, buffer, level + 1, printCount);
        }
    }
}

void printTrie(struct TrieNode *root, char *key, int maxPrints)
{
    int length = strlen(key);
    struct TrieNode *cur = root;
    for (int i = 0; i < length; i++)
    {
        int index = mapToIndex(key[i]);
        cur = cur->children[index];
    }

    if (trieNodeEmpty(cur))
    {
        puts("No children");
    }
    else
    {
        char buffer[50];
        printTrieRoot(cur, key, buffer, 0, &maxPrints);
    }
}

int main()
{
    char keys[][8] = {"the", "a", "there", "answer", "any",
                      "by", "bye", "their"};

    char output[][32] = {"Not present in trie", "Present in trie"};

    struct TrieNode *root = newTrieNode();

    // Construct trie
    for (int i = 0; i < 8; i++)
        insertTrie(root, keys[i]);

    // search Trie for different keys
    printf("%s --- %s\n", "the", output[searchTrie(root, "a")]);
    deleteTrie(root, "a");
    printf("%s --- %s\n", "the", output[searchTrie(root, "a")]);
    printf("%s --- %s\n", "their", output[searchTrie(root, "their")]);
    printf("%s --- %s\n", "thaw", output[searchTrie(root, "thaw")]);

    printTrie(root, "by", 4);
}

#endif