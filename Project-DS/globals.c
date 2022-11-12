#include "./dataStructures/table.h"
#include "./utils/gameUtils.h"
#include <stdbool.h>

char *userPath = "./database/users.txt";
char *borrowPath = "database/borrows.txt";
char *filmsPath = "database/films.txt";

struct User currentUser;
struct Row genres;