
#ifndef STRUCTS_H
#define STRUCTS_H

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
	char symbol;
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
	char *name;
	Node playerNode;
	PlayerAttributes attributes;
	Backpack backpack;
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

typedef struct Score
{
	char *name;
	int score;
} Score;

typedef struct PlayerDatabase
{
	char *name;
	int money;
	int xp;
	int level;
	int hp;
	double energy;
	int armor;
} PlayerDatabase;

// Global game data

typedef struct GameData
{
	Player currentPlayer;
	Enemy *enemies;
	int enemyCount;
	Node *bullets;
	int bulletCount;
} GameData;

#endif