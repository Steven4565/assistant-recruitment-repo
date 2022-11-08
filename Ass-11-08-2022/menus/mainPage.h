#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/inputUtils.h"
#include "../utils/outputUtils.h"
#include "../utils/validators.h"
#include "../utils/fileUtils.h"
#include "../utils/utils.h"

#include "adminPage.h"
#include "clientPage.h"

void login()
{
	char username[50], password[50];
	getInputString("Enter your username", usernameLoginValidator, username);
	if (username[0] == '0')
		return;

	getInputString("Enter your password", passwordLoginValidator, password);
	if (password[0] == '0')
		return;

	bool admin = true; // TODO: make a function to check this
	if (admin)
	{
		while (adminPage())
			;
	}
	else
	{
		while (clientPage())
			;
	}
}

void regist()
{
	char username[50], password[50];
	getInputString("Enter your username", usernameRegistValidator, username);
	if (username[0] == '0')
		return;

	getInputString("Enter your password", passwordRegistValidator, password);
	if (password[0] == '0')
		return;

	puts("creating new user");
	getEnter();

	while (clientPage())
		;
}

bool menuPage()
{
	clrscr();
	puts("MyDramaList");
	puts("===========");

	char *menus[] = {"Login", "Register", "Exit"};
	int input;
	getInputRange(menus, 3, 1, 3, &input);

	if (input == 3)
		return false;

	if (input == 1)
	{
		login();
	}
	else if (input == 2)
	{
		regist();
	}

	return true;
}

#endif