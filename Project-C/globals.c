#include "globals.h"
#include "structs.h"

const int SIZE_LOBBY_X = 22;
const int SIZE_LOBBY_Y = 35;

const int SIZE_GAME_X = 22;
const int SIZE_GAME_Y = 50;

const char *EMPTY_SPACE = "     ";
const char *EMPTY_50 = "                                                  ";

const int SPACE_1_W = 5;
const int SPACE_1_H = 5;

const int SPACE_2_W = 7;
const int SPACE_2_H = 5;

const int SPACE_3_W = 3;
const int SPACE_3_H = 4;

const int SPACE_4_W = 7;
const int SPACE_4_H = 5;

const int TOTAL_SPACE = 4;

const int ENEMY_WIDTH = 3;

// sprite, width, height
Sprite space1 = {NULL, 5, 5};
Sprite space2 = {NULL, 7, 5};
Sprite space3 = {NULL, 3, 4};
Sprite space4 = {NULL, 7, 5};
Sprite board = {NULL, 50, 22};
Sprite lobby = {NULL, 35, 22};
Sprite boardOpenedGate = {NULL, 0, 0};
Sprite enemy1 = {NULL, 3 ,1};
Sprite enemy2 = {NULL, 3, 1};
Sprite enemy3= {NULL, 3, 1};
