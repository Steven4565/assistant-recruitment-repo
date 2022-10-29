#ifndef GAME_H
#define GAME_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "../utils/eventTimer.h"
#include "../globals.h"
#include "../utils/printUtils.h"
#include "../utils/inputUtils.h"
#include "../utils/gameUtils.h"
#include "../events/handlers.h"

void render()
{
	clrscr();
	for (int i = 0; i < board.h; i++)
	{
		for (int j = 0; j < board.w; j++)
		{
			char spriteChar = getBoardChar(j, i);
			printf("%c", spriteChar);
		};
		// render messages next to board
		PlayerAttributes attr = game.currentPlayer.attributes;
		Player player = game.currentPlayer;
		if (i == 2)
			printf("\tName: %s", lobbyData.playerData.name);
		if (i == 3)
			printf("\tLevel: %d", lobbyData.playerData.level);
		if (i == 5)
			printf("\tX: %d | y: %d", player.playerNode.pos.x, player.playerNode.pos.y);
		if (i == 8)
			printf("\tScore: %d", attr.score);
		if (i == 9)
			printf("\t[HP: %d/%d]", attr.hp, attr.maxHp);
		if (i == 10)
			printf("\tArmor: %d/%d", attr.armor, attr.maxArmor);
		if (i == 11)
			printf("\tEnergy: %.0lf/%.0lf", attr.energy, attr.maxEnergy);
		if (i == 12)
			printf("\tBullets: %d/10", attr.bullets);

		if (i == 15)
			printf("\t%s", game.message);

		puts("");
	}
}

void handleShoot()
{
	Vector2D startPos = {.x = game.currentPlayer.playerNode.pos.x + 2, .y = game.currentPlayer.playerNode.pos.y - 1};
	Vector2D bulletDir = {.x = 0, .y = -1};
	shootBullet(startPos, bulletDir, bulletOwner_player, 1);
}

void handleSkill()
{
	if (game.currentPlayer.attributes.bullets < 3 || game.currentPlayer.attributes.energy < 30)
		return;

	Vector2D startPos = {.x = game.currentPlayer.playerNode.pos.x + 2, .y = game.currentPlayer.playerNode.pos.y - 1};
	Vector2D bulletDir1 = {.x = 1, .y = -1};
	Vector2D bulletDir2 = {.x = 0, .y = -1};
	Vector2D bulletDir3 = {.x = -1, .y = -1};
	shootBullet(startPos, bulletDir1, bulletOwner_player, 1);
	shootBullet(startPos, bulletDir2, bulletOwner_player, 1);
	shootBullet(startPos, bulletDir3, bulletOwner_player, 1);

	game.currentPlayer.attributes.energy -= 30;
}

void handleGameplayInput(char input, Vector2D *moveVector)
{
	if (input == '\0')
		return;

	if (input == 'w' || input == 'a' || input == 's' || input == 'd')
	{
		handleMoveVector(input, moveVector);
		return;
	}

	switch (input)
	{
	case ' ':
		handleShoot();
		break;
	case 'g':
		// TODO: if has bomb, fire onbonb
		// else: fire onMessage("You don't have any bombs")
		break;
	case 'r':
		game.message = "Reloading...";
		activateTimer(&game.timers.reloadTimer, 1000);
		activateTimer(&game.timers.resetMessageTimer, 1000);
		break;
	case 'f':
		handleSkill();
		break;
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	default:
		break;
	}
}

void initGame()
{
	Node playerNode = {{23, 15}, 5, 5};
	PlayerEntry currentPlayer = lobbyData.playerData;
	PlayerAttributes attr = {.bullets = 0,
													 .xp = currentPlayer.xp,
													 .level = currentPlayer.level,
													 .money = currentPlayer.money,
													 .hp = currentPlayer.hp,
													 .energy = currentPlayer.energy,
													 .armor = currentPlayer.armor,
													 .maxHp = currentPlayer.hp,
													 .maxEnergy = currentPlayer.energy,
													 .maxArmor = currentPlayer.armor,
													 .score = 0};
	Player player = {
			.playerNode = playerNode,
			.attributes = attr,
	};

	game.enemyCount = 0;
	game.enemyIndex = 0;
	game.bulletCount = 0;
	game.bulletIndex = 0;
	game.currentPlayer = player;

	game.currentPlayer.attributes.bullets = 10;

	TimerCollection *timers = &game.timers;
	Timer frameTimer = {clock(), 40, 0, true};
	Timer generateEnemyTimer = {clock(), 6000, 0, true};
	Timer moveEnemyTimer = {clock(), 3000, 0, true};
	Timer reloadTimer = {clock(), 1000, 0, false};
	Timer resetMessageTimer = {clock(), 1000, 0, false};
	Timer enemyShootTimer = {clock(), 3000 + getRandom(0, 1000), 0, true};
	timers->frameTimer = frameTimer;
	timers->generateEnemyTimer = generateEnemyTimer;
	timers->moveEnemyTimer = moveEnemyTimer;
	timers->reloadTimer = reloadTimer;
	timers->resetMessageTimer = resetMessageTimer;
	timers->enemyShootTimer = enemyShootTimer;

	game.message = "";
	game.gameOver = false;
}

void gameLoop()
{
	// Render
	clrscr();
	render();

	// Get input (if space then no input)
	char input = getKbdInput();
	Vector2D moveVector = {0, 0};
	handleGameplayInput(input, &moveVector);
	movePlayerNode(board, &game.currentPlayer.playerNode, moveVector);

	// RUN EVENT CALLBACKS (if flag is on, run callback)
	handleMessageReset();
	handleGenerateEnemies();
	handleMoveEnemies();
	handleEnemyShoot();
	handleReload();
	handleMoveBullets();
	if (game.currentPlayer.attributes.energy < game.currentPlayer.attributes.maxEnergy)
		game.currentPlayer.attributes.energy += 0.1;
}

void startEventLoop()
{

	initGame();
	while (!game.gameOver)
	{
		// updates timer msec
		setTimerInterval(&game.timers.frameTimer);
		setTimerInterval(&game.timers.generateEnemyTimer);
		setTimerInterval(&game.timers.moveEnemyTimer);
		setTimerInterval(&game.timers.reloadTimer);
		setTimerInterval(&game.timers.resetMessageTimer);
		setTimerInterval(&game.timers.enemyShootTimer);

		// turns the bool on when msec > delay, resets msec
		runEventCallback(&game.timers.frameTimer, &gameLoop);
		setEventCallbackFlag(&game.timers.generateEnemyTimer, &events.generateEnemyFlag);
		setEventCallbackFlag(&game.timers.moveEnemyTimer, &events.moveEnemyFlag);
		setEventCallbackFlag(&game.timers.reloadTimer, &events.reloadFlag);
		setEventCallbackFlag(&game.timers.resetMessageTimer, &events.resetMessageFlag);
		setEventCallbackFlag(&game.timers.enemyShootTimer, &events.enemyShootFlag);

		// for optimization
		usleep(20000);
	}
}

#endif