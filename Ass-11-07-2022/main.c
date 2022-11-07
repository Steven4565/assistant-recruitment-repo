#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils/linkedList.h"

struct LinkedList list;

void viewAircrafts()
{
	puts("aircrafts: ");
	printList(&list);
	getchar();
}

void addAircraft()
{
	puts("input number: ");
	int num;
	scanf("%d%*c", &num);
	pushTail(&list, num);
}

void updateAircraft()
{
	int query, target;
	puts("input number you want to replace");
	scanf("%d%*c", &query);
	puts("input value to replace with");
	scanf("%d%*c", &target);
	replaceVal(&list, query, target);
}

void deleteAircraft()
{
	puts("input number: ");
	int num;
	scanf("%d%*c", &num);
	popMid(&list, num);
}

void printManageAirCraftMenu()
{
	printf("\e[1;1H\e[2J");
	puts("Manage aircraft menu: ");
	puts("1. View Aircrafts");
	puts("2. Add Aircraft");
	puts("3. Update Aircraft");
	puts("4. Delete Aircraft");
	puts("5. Exit");
}

void handleManageAirCraftInput(char input, bool *end)
{
	switch (input)
	{
	case '1':
		viewAircrafts();
		break;
	case '2':
		addAircraft();
		break;
	case '3':
		updateAircraft();
		break;
	case '4':
		deleteAircraft();
		break;
	case '5':
		*end = true;
		break;
	default:
		break;
	}
}

void manageAirCraftLoop()
{
	bool endManageAircraft = false;
	while (!endManageAircraft)
	{
		printManageAirCraftMenu();
		char input = getchar();
		getchar();
		handleManageAirCraftInput(input, &endManageAircraft);
	}
}

void manageScheduleLoop()
{
}

void printMainMenu()
{
	printf("\e[1;1H\e[2J");
	puts("Choose menu: ");
	puts("1. Manage Aircraft");
	puts("2. Manage Schedule");
	puts("3. Exit");
	printf("Input option >> ");
}

void handleMainMenuInput(char input, bool *ended)
{
	switch (input)
	{
	case '1':
		manageAirCraftLoop();
		break;
	case '2':

		break;
	case '3':
		*ended = true;
		break;
	default:
		break;
	}
}

int main()
{
	initList(&list);
	bool programEnded = false;

	while (!programEnded)
	{
		printMainMenu();
		char input = getchar();
		getchar();
		handleMainMenuInput(input, &programEnded);
	}

	return 0;
}
