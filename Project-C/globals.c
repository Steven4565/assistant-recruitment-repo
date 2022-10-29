#include "globals.h"
#include "structs.h"

// sprite, width, height

Sprite space1 = {5, 5};
Sprite space2 = {7, 5};
Sprite space3 = {3, 4};
Sprite space4 = {7, 5};
Sprite board = {49, 22};
Sprite lobby = {34, 22};
Sprite enemy1 = {3, 1};
Sprite enemy2 = {3, 1};
Sprite enemy3 = {3, 1};

Vector2D lobbyUpgrade = {6, 16};
Vector2D lobbyShop = {27, 16};

PlayerEntry playerEntries[100];
int playerEntryCount = 0;

EventCollection events = {0, 0};

GameData game;
LobbyData lobbyData;