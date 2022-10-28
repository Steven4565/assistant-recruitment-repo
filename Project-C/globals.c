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

Sprite space1 = {5, 5};
Sprite space2 = {7, 5};
Sprite space3 = {3, 4};
Sprite space4 = {7, 5};
Sprite board = {49, 22};
Sprite lobby = {34, 22};
Sprite lobbyOpenedGate = {34, 22};
Sprite enemy1 = {3, 1};
Sprite enemy2 = {3, 1};
Sprite enemy3 = {3, 1};

Vector2D lobbyUpgrade = {6, 16};
Vector2D lobbyShop = {27, 16};
