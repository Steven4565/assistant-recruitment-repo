
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
	bool generateEnemyFlag;
	bool moveEnemyFlag;
	bool reloadFlag;
	bool resetMessageFlag;
	bool enemyShootFlag;
} EventCollection;

typedef struct TimerCollection
{
	Timer frameTimer;
	Timer generateEnemyTimer;
	Timer moveEnemyTimer;
	Timer reloadTimer;
	Timer resetMessageTimer;
	Timer enemyShootTimer;
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
	int score;
	int bullets;
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
	Vector2D direction;
	int damage;
	int index;
} Enemy;

typedef struct Bullet
{
	Node bullet;
	Vector2D direction;
	int bulletOwner;
	int bulletDamage;
	int index;
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
	bool gameOver;
	Player currentPlayer;
	Enemy enemies[500];
	int enemyCount;
	int enemyIndex;
	Bullet bullets[1000];
	int bulletCount;
	int bulletIndex;
	char *message;
	TimerCollection timers;
} GameData;

#endif