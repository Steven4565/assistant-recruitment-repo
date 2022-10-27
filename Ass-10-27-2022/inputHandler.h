#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "validator.h"
#include "inputHandler.h"
#include "fileHandler.h"

void printMenu()
{
	puts("1. Add telephone book");
	puts("2. Search telephone book");
	puts("3. View telephone book");
	puts("4. Exit");
	printString(">>");
}

void add()
{
	// get name
	printString("input name (3-100 char long): ");
	char name[1000];
	getLine(name);
	while (!validateInt(strlen(name), 3, 100))
	{
		printString("input name (3-100 char long): ");
		getLine(name);
	}

	// get phone number
	printString("Input phone number (starts with 0, 10-12 char long, must be numbers): ");
	char phoneNumber[1000];
	getLine(phoneNumber);
	while (strlen(phoneNumber) < 10 || strlen(phoneNumber) > 12 || phoneNumber[0] != '0' || !isAllNumbers(phoneNumber, strlen(phoneNumber)))
	{
		printString("Input phone number (starts with 0, 10-12 char long, must be numbers): ");
		getLine(phoneNumber);
	}

	// get address
	printString("Input address (must end with Street): ");
	char address[1000];
	getLine(address);
	while (strlen(address) < 6 || !endsWith(address, strlen(address), "Street", 6))
	{
		printString("Input address (must end with Street");
		getLine(address);
	}

	// puts("");
	// puts(name);
	// puts(phoneNumber);
	// puts(address);
	// getchar();

	insertEntry(name, phoneNumber, address);
}

void search()
{
	// get name
	printString("input name (3-100 char long): ");
	char name[1000];
	getLine(name);
	while (!validateInt(strlen(name), 3, 100))
	{
		printString("input name (3-100 char long): ");
		getLine(name);
	}

	char nameArr[100][100];
	char numberArr[100][100];
	char addressArr[100][100];
	int length;
	getFileEntries(nameArr, numberArr, addressArr, &length);
	sortArrayDesc(nameArr, numberArr, addressArr, length);
	int index = searchEntry(nameArr, 0, length - 1, name);

	// for (int k = 0; k < length; k++)
	// {
	// 	printf("%s\n", nameArr[k]);
	// }
	// puts("");
	// printf("index: %d\n", index);
	if (index == -1)
	{
		puts("No entry with that name");
		getchar();
		return;
	}

	printf("Name\t: %s\n", nameArr[index]);
	printf("No\t: %s\n", numberArr[index]);
	printf("Address\t: %s\n", addressArr[index]);
}

void view()
{
	printString("Input option (DESC/ASC): ");
	char viewInput[100];
	scanf("%s", viewInput);
	while (stricmp(viewInput, "ASC") != 0 && stricmp(viewInput, "DESC") != 0)
	{
		scanf("%s%*c", viewInput);
	}

	char nameArr[100][100];
	char numberArr[100][100];
	char addressArr[100][100];
	int length;
	getFileEntries(nameArr, numberArr, addressArr, &length);

	if (stricmp(viewInput, "asc") == 0)
	{
		printf("compare: %d\nstring: %s\n", stricmp(viewInput, "asc"), viewInput);
		sortArrayAsc(nameArr, numberArr, addressArr, length);
		for (int i = 0; i < length; i++)
		{
			printf("no: %d\nname: %s\nnumber: %s\naddress: %s\n\n", i + 1, nameArr[i], numberArr[i], addressArr[i]);
		}
	}
	else
	{
		sortArrayDesc(nameArr, numberArr, addressArr, length);
		for (int i = 0; i < length; i++)
		{
			printf("no: %d\nname: %s\nnumber: %s\naddress: %s\n\n", i + 1, nameArr[i], numberArr[i], addressArr[i]);
		}
	}

	getchar();
}

void handleMenuInput(char input, bool *endProgram)
{
	switch (input)
	{
	case '1':
		add();
		break;
	case '2':
		search();
		break;
	case '3':
		view();
		break;
	case '4':
		puts("program exitted. Press enter to continue...");
		getchar();
		*endProgram = true;
		break;
	default:
		break;
	}
}

#endif