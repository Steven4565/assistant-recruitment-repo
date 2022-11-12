#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "fileUtils.h"
#include "../globals.h"

bool validateMenu(char *input)
{
	if (strcmp(input, "1") == 0)
		return true;
	else
		return false;
}

bool intValidator(char *input)
{
	if (!isNumber(input))
	{
		puts("Please input a number");
		return false;
	}

	return true;
}

bool nameValidator(char *name)
{
	if (strlen(name) >= 2)
		return true;
	else
		return false;
}

bool usernameLoginValidator(char *name)
{
	char row[150] = "";
	getUser(userPath, name, row);
	if (strlen(row) == 0)
	{
		puts("Username not found");
		return false;
	}
	return true;
}

bool usernameRegisterValidator(char *name)
{
	int length = strlen(name);
	if (length < 8 || length > 30)
	{
		puts("Username must be between 8 and 30 char long\n");
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (!isalpha(name[i]) && !name[i] != ' ' && !name[i] != '_' && !isdigit(name[i]))
		{
			puts("Name must be alphanumeric with spaces or underscores");
			return false;
		}
	}

	char row[150];
	getUser(userPath, name, row);
	if (strlen(row) != 0)
	{
		puts("Username already exists");
		return false;
	}

	return true;
}

bool passwordRegisterValidator(char *password)
{
	int length = strlen(password);
	if (length < 8 || length > 30)
	{
		puts("Password must be between 8 and 30 characters long");
		return false;
	}
	return true;
}

#endif