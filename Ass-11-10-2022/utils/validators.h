#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <string.h>
#include <stdio.h>

#include "../globals.h"
#include "../dataStructures/hashTable.h"

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

bool ageValidator(int age)
{
	if (age >= 10)
		return true;
	else
		return false;
}

bool weightValidator(int weight)
{
	if (weight >= 30)
		return true;
	else
		return false;
}

bool genderValidator(char *gender)
{
	if (strcmpi(gender, "male") == 0 || strcmpi(gender, "female") == 0)
		return true;
	else
		return false;
}

bool codeValidator(char *code)
{
	if (hashTable[getHash(code)] == NULL)
	{
		printf("Please input a valid code\n");
		return false;
	}
	return true;
}

#endif