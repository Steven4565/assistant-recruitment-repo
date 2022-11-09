#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <string.h>
#include <stdio.h>

bool validateMenu(char *input)
{
	if (strcmp(input, "1") == 0)
		return true;
	else
		return false;
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
	if (strcmpi(gender, "male") == 0 || strcmpi(gender, "female"))
		return true;
	else
		return false;
}

#endif