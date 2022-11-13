#include "./dataStructures/table.h"
#include "./dataStructures/hashTable.h"
#include "./dataStructures/trie.h"
#include "./utils/gameUtils.h"
#include <stdbool.h>

char *userPath = "./database/users.txt";
char *borrowPath = "database/borrows.txt";
char *filmsPath = "database/films.txt";

struct User currentUser;
struct Row genres;
struct TrieNode *filmsList;
struct HashEntry *favoritedFilms[HASH_TABLE_SIZE];