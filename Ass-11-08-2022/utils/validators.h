#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <string.h>
#include <stdio.h>

bool validateMenu(char *input)
{
	if (strcmp(input, "1") == 0)
	{
		return true;
	}
	else
		return false;
}

bool usernameLoginValidator(char *input)
{
	return true;
}

bool passwordLoginValidator(char *input)
{
	return true;
}

bool usernameRegistValidator(char *input)
{
	return true;
}

bool passwordRegistValidator(char *input)
{
	return true;
}

#endif