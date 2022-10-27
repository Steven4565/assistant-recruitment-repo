#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "validator.h"
#include "inputHandler.h"

void printMenu()
{
	puts("1. Add telephone book");
	puts("2. Search telephone book");
	puts("3. View telephone book");
	puts("4. Exit");
	printString(">>");
}

void handleMenuInput(char input, bool *endProgram)
{
	switch (input)
	{
	case '1':
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

		puts("");
		puts(name);
		puts(phoneNumber);
		puts(address);
		getchar();

		// TODO: input to database

		break;
	case '2':
		// get name
		printString("input name (3-100 char long): ");
		char name2[1000];
		getLine(name2);
		while (!validateInt(strlen(name2), 3, 100))
		{
			printString("input name (3-100 char long): ");
			getLine(name2);
		}

		// TODO: search database

		break;
	case '3':
		// TODO:
		break;
	case '4':
		puts("program exitted. Press enter to continue...");
		getchar();
		*endProgram = false;
		break;
	default:
		break;
	}
}

#endif