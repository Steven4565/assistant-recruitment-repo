#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "../utils/inputUtils.h"
#include "../utils/outputUtils.h"
#include "../utils/validators.h"
#include "../utils/fileUtils.h"
#include "../utils/utils.h"
#include "../utils/gameUtils.h"

#include "./menuOptionsPage.h"

#include "../globals.h"

void login()
{
	char username[50];
	getInputString("Input username", usernameLoginValidator, username);

	char row[150];
	getUser(userPath, username, row);
	parseUser(&currentUser, row);

	char passBuffer[50] = "";
	char inputBuffer;
	while (true)
	{
		clrscr();
		printf("Password >> ");
		for (int i = 0; i < strlen(passBuffer); i++)
		{
			printf("*");
		}

		inputBuffer = getch();
		if (inputBuffer == '\r')
			break;
		else if (inputBuffer == '\b')
		{
			passBuffer[strlen(passBuffer) - 1] = '\0';
		}
		else
		{
			printf("%c", inputBuffer);
			strncat(passBuffer, &inputBuffer, 1);
		}
	}

	puts("");
	if (strlen(passBuffer) > 0 && strcmp(passBuffer, "admin") == 0 && strcmp(username, "admin") == 0)
	{
		puts("Successfully logged in as admin");
		while (menuOptionsPage())
			;
		getEnter();
	}
	else if (strlen(passBuffer) > 0 && strcmp(passBuffer, currentUser.pass) == 0)
	{
		puts("Successfully logged in");
		getEnter();
		while (menuOptionsPage())
			;
	}
	else
	{
		puts("Incorrect Password");
		getEnter();
	}
}

void regist()
{
	char *username;
	char *password;
	getInputString("Input new username [8-30 char long]", usernameLoginValidator, username);
	getInputString("Input new password", passwordRegisterValidator, password);

	puts("Successfully registered");
	getEnter();
	// TODO: writeRow, set user data
}

bool mainPage()
{
	clrscr();
	puts("filMZ");
	puts("===========");

	char *menus[] = {
		"Exit",
		"Login",
		"Register",
	};
	int input;
	getInputRange(menus, 3, 0, 2, true, &input);

	// Exit Program
	if (input == 0)
		return false;

	switch (input)
	{
	case 1:
		login();
		break;
	case 2:
		regist();
		break;
	default:
		break;
	}

	return true;
}

#endif