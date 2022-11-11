#ifndef BST_H
#define BST_H

struct TrieNode
{
	struct TrieNode *children[50];
	bool isEndOfWord;
};

#endif