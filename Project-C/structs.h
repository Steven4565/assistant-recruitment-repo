
#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>

typedef struct Timer
{
	clock_t before;
	int delay;
	int msec;
	bool on;
} Timer;

typedef struct EventCollection
{
	bool onEnemyEmitted;
	bool onResetMessageEmitted;
} EventCollection;

typedef struct TimerCollection
{
	Timer frameTimer;
	Timer enemyTimer;
	Timer resetMessageTimer;
} TimerCollection;

typedef struct Vector2D
{
	int x;
	int y;
} Vector2D;

typedef struct Node
{
	Vector2D pos; // top left coord
	int w;
	int h;
} Node;

typedef struct Sprite
{
	int w;
	int h;
	char sprite[52][52];
} Sprite;

typedef struct PlayerAttributes
{
	int xp;
	int level;
	int money;
	int hp;
	double energy;
	int armor;
	int maxHp;
	double maxEnergy;
	int maxArmor;
} PlayerAttributes;

typedef struct Backpack
{
	int potion;
	int maxPotion;
	int energyDrink;
	int maxEnergyDrink;
	int bomb;
} Backpack;

typedef struct Player
{
	Node playerNode;
	PlayerAttributes attributes;
} Player;

typedef struct Enemy
{
	Node enemy;
	int enemyType;
} Enemy;

typedef struct Bullet
{
	Node bullet;
	int bulletOwner;
	int bulletDamage;
	int bulletType;
} Bullet;

// DATABASE TYPES

typedef struct PlayerEntry
{
	char name[50];
	int money;
	int xp;
	int level;
	int hp;
	double energy;
	int armor;
	int damage;
} PlayerEntry;

// Global game data

typedef struct LobbyData
{
	PlayerEntry playerData;
	Node player;
	Backpack backpack;
} LobbyData;

typedef struct GameData
{
	Player currentPlayer;
	Enemy enemies[100];
	int enemyCount;
	Node bullets[200];
	int bulletCount;
	char *message;
	TimerCollection timers;
} GameData;

#endif