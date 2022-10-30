#ifndef LOBBY_H
#define LOBBY_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "../globals.h"
#include "../utils/eventTimer.h"
#include "../utils/printUtils.h"
#include "../utils/inputUtils.h"
#include "../utils/gameUtils.h"
#include "game.h"

char *getLobbyMessage(Vector2D player)
{
	int x = player.x;
	int y = player.y;
	if (checkShops(lobbyShop, player))
	{
		return "Press SPACE to open item shop";
	}

	if (checkShops(lobbyUpgrade, player))
	{
		return "Press SPACE to open upgrades";
	}

	if (x == 5 && (y >= 9 && y <= 11))
	{
		return "Press SPACE to check leaderboards";
	}

	if (x == 17 && y == 20)
	{
		return "Press SPACE to exit";
	}

	if (x == 17 && y == 10)
	{
		return "Press SPACE to start game";
	}

	return "";
}

void renderLobby(Vector2D player)
{
	char *message;
	clrscr();
	for (int i = 0; i < lobby.h; i++)
	{
		for (int j = 0; j < lobby.w; j++)
		{
			char spriteChar = lobby.sprite[i][j];

			// render player
			if (j == player.x && i == player.y)
			{
				spriteChar = 'P';
			}

			// check for messages, set here
			message = getLobbyMessage(player);

			printf("%c", spriteChar);
		};
		// render messages next to board
		if (i == 7)
			printf("\t[%s]", lobbyData.playerData.name);
		if (i == 8)
			printf("\tLevel : %d", lobbyData.playerData.level);
		if (i == 9)
			printf("\tMoney : %d", lobbyData.playerData.money);
		if (i == 12)
			printf("\tPlayer: %d, %d", player.x, player.y);
		else if (i == 15)
			printf("\t%s", message);
		puts("");
	}
}

void handleBuyItem(int itemIndex)
{
	int upgradePrices[] = {5, 20, 3, 15, 10};
	char *itemLabels[] = {"Potion", "Max Potion", "Energy Drink", "Max Energy Drink", "Bomb"};

	Backpack *bp = &lobbyData.backpack;
	int *backpackItemPointers[] = {&bp->potion,
																 &bp->maxPotion,
																 &bp->energyDrink,
																 &bp->maxEnergyDrink,
																 &bp->bomb};
	int money = lobbyData.playerData.money;

	printf("How many %s do you want to buy?\n", itemLabels[itemIndex]);
	printString("- ");

	int amount;
	scanf("%d%*c", &amount);

	puts("");
	if (money < amount * upgradePrices[itemIndex])
	{
		puts("You don't have enough money! (press any key to continue)\n");
	}
	else
	{
		printf("Successfully purchased %d %s (press any key to continue)\n", amount, itemLabels[itemIndex]);
		lobbyData.playerData.money -= amount * upgradePrices[itemIndex];
		*(backpackItemPointers[itemIndex]) += amount;
		if (DEBUG)
		{
			printf("%s\n", itemLabels[itemIndex]);
			printInt("amount", lobbyData.backpack.bomb);
		}
	}
	getch();
}

void enterItemShop()
{
	Backpack *backpack = &lobbyData.backpack;
	char *options[] = {
			"1. Potion [$5]",
			"2. Max Potion [$20]",
			"3. Energy Drink [$3]",
			"4. Max Energy Drink [$15]",
			"5. Bomb [$10]",
	};
	int optionCount = 5;

	bool inItemShop = true;
	int itemIndex = 0;

	printMenu(itemIndex, options, optionCount);

	while (inItemShop)
	{
		clrscr();
		puts("Welcome to the item shop");
		puts("========================");
		printMenu(itemIndex, options, playerEntryCount);
		char input = getch();
		if (getMenuScrollInput(input, &itemIndex, 0, optionCount) == -1)
		{
			if (itemIndex > optionCount)
				inItemShop = false;

			handleBuyItem(itemIndex);
			inItemShop = false;
		}
	}
}

void handleUpgrade(int upgradeIndex)
{
	PlayerEntry *entry = &lobbyData.playerData;

	int upgradePrices[] = {50, 50, 30};																	 // price
	int upgradeValues[] = {50, 50, 5};																	 // value to add when upgraded
	int currentValues[] = {entry->hp, (int)entry->energy, entry->armor}; // player's current value
	int maxValues[] = {300, 500, 30};																		 // max value

	int money = lobbyData.playerData.money;

	puts("");
	if (currentValues[upgradeIndex] + upgradeValues[upgradeIndex] > maxValues[upgradeIndex])
	{
		puts("Skill cannot be upgraded anymore(press any key to continue)\n");
	}
	else if (money < upgradePrices[upgradeIndex])
	{
		puts("You don't have enough money! (press any key to continue)\n");
	}
	else
	{
		puts("Successfully upgraded skills (press any key to continue)\n");
		entry->money -= upgradePrices[upgradeIndex];
		switch (upgradeIndex)
		{
		case 0:
			// Upgrade HP
			entry->hp += upgradeValues[upgradeIndex];
			break;
		case 1:
			// Upgrade Energy
			entry->energy += upgradeValues[upgradeIndex];
			break;
		case 2:
			// Upgrade Armor
			entry->armor += upgradeValues[upgradeIndex];
			break;
		}
		if (DEBUG)
		{
			printf("%d\n", entry->hp);
		}
	}
	getch();
}

void enterUpgradeShop()
{
	PlayerEntry entry = lobbyData.playerData;

	char options[3][50];
	sprintf(options[0], "1. HP %d/300 - $50", entry.hp);
	sprintf(options[1], "2. Energy %.0lf/500 - $50", entry.energy);
	sprintf(options[2], "3. Armor %d/30 - $30", entry.armor);
	char *options_row[] = {options[0], options[1], options[2]}; // Because you can't convert a matrix directly into a double pointer
	int optionCount = 3;

	bool inUpgradeShop = true;
	int upgradeIndex = 0;

	while (inUpgradeShop)
	{
		clrscr();
		puts("Do you need anything to upgrade?");
		printMenu(upgradeIndex, options_row, optionCount);
		char input = getch();
		if (getMenuScrollInput(input, &upgradeIndex, 0, optionCount) == -1)
		{
			if (upgradeIndex < optionCount)
			{
				printInt("index", upgradeIndex);
			}

			inUpgradeShop = false;
		}
	}
}

void openBackpack()
{
	Backpack backpack = lobbyData.backpack;
	clrscr();
	printf("%s's backpack\n", lobbyData.playerData.name);
	printf("==================\n");
	(backpack.potion > 0 ? printf("- Potion: %d\n", backpack.potion) : 0);
	(backpack.maxPotion > 0 ? printf("- Max Potion: %d\n", backpack.maxPotion) : 0);
	(backpack.energyDrink > 0 ? printf("- Enery Drink: %d\n", backpack.energyDrink) : 0);
	(backpack.maxEnergyDrink > 0 ? printf("- Max Energy Drink: %d\n", backpack.maxEnergyDrink) : 0);
	(backpack.bomb > 0 ? printf("- Bomb: %d\n", backpack.bomb) : 0);
	puts("");
	puts("Back to game (press any key)");
	getch();
}

void handleLobbyInteract(Vector2D player, char inputChar, bool *runLobby)
{
	int x = player.x;
	int y = player.y;

	if (checkShops(lobbyShop, player))
	{
		enterItemShop();
	}

	if (checkShops(lobbyUpgrade, player))
	{
		enterUpgradeShop();
	}

	if (x == 5 && (y >= 9 && y <= 11))
	{
		getLeaderboard();
	}

	if (x == 17 && y == 20)
	{
		*runLobby = false;
	}

	if (x == 17 && y == 10)
	{
		startEventLoop();
	}
}

void handleLobbyInput(char input, bool *runLobby)
{
	switch (input)
	{
	case ' ':
		handleLobbyInteract(lobbyData.player.pos, input, runLobby);
		break;
	case 'b':
		openBackpack();
		break;
	}
}

void initLobby(int entryIndex)
{
	Vector2D player = {17, 19};
	Backpack backpack = {0, 0, 0, 0, 0}; // TODO: init backpack here

	lobbyData.player.pos = player;
	lobbyData.player.h = 1;
	lobbyData.player.w = 1;
	lobbyData.playerData = playerEntries[entryIndex];
}

void lobbyLoop(int entryIndex)
{
	bool runLobby = true;

	initLobby(entryIndex);

	renderLobby(lobbyData.player.pos);

	while (runLobby)
	{
		clrscr();
		renderLobby(lobbyData.player.pos);

		Vector2D moveVector = {0, 0};
		char inputChar = getch();
		handleMoveVector(inputChar, &moveVector);

		handleLobbyInput(inputChar, &runLobby);

		movePlayerNode(lobby, &lobbyData.player, moveVector);

		usleep(10000);
	}
}

#endif