#ifndef DELETE_H
#define DELETE_H

#include "../utils.h"
#include "../database/api/viewEntry.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void convertToUpperCase(char *input, char *output)
{
	for (int i = 0; i < strlen(input); i++)
	{
		char char_ = input[i];
		if (isalpha(char_))
		{
			char_ = toupper(char_);
		}
		strncat(output, &char_, 1);
	}
}

void inputCodeToDelete(char *input)
{
	do
	{
		printf("Input the stock code [<= 7 characters][case insensitive][type 'cancel' to cancel the deletion]: ");
		getInputString(input);

	} while (strlen(input) > 7);
}

void deleteEntry(int index)
{
	moveEntriesForward(index);
	dbLen--;
}

void deleteStock()
{
	viewEntry();
	puts("");

	// get input
	char codeInput[1000];
	inputCodeToDelete(codeInput);

	char formattedCode[10] = "";
	convertToUpperCase(codeInput, formattedCode);
	if (DEBUG)
		printf("formatted code: %s\n", formattedCode);

	if (compareString(formattedCode, "CANCEL", 6))
	{
		puts("deletion progress is aborted");
		puts("Press enter to continue...");
		getchar();
		return;
	}

	int codeIndex = checkIfCodeExists(formattedCode);

	// check if code in database is found
	if (codeIndex == -1)
	{
		printf("There are no stocks with code %s.\n", formattedCode);
		puts("Press enter to continue...");
		getchar();
		return;
	}

	// delete entry
	deleteEntry(codeIndex);

	printf("successfully deleted %s\n", formattedCode);
	puts("Press enter to continue...");
	getchar();
}

#endif