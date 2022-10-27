#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "utils.h"
#include "validator.h"
#include "inputHandler.h"
#include "fileHandler.h"

int main()
{
	// bool endProgram = false;
	// while (!endProgram)
	// {
	// 	printMenu();
	// 	char input;
	// 	scanf("%c%*c", &input);
	// 	while (!validateInt(input, '1', '4'))
	// 	{
	// 		printInt(validateInt(input, '1', '4'));
	// 		clrscr();
	// 		printMenu();
	// 		scanf("%c%*c", &input);
	// 	}

	// 	handleMenuInput(input, &endProgram);
	// }

	char *nameArr[100];
	char *numberArr[100];
	char *addressArr[100];
	int length;
	getFileEntries(nameArr, numberArr, addressArr, &length);
	printInt(length);
	for (int i = 0; i < length; i++)
	{
		puts(nameArr[i]);
		puts(numberArr[i]);
		puts(addressArr[i]);
		puts("");
	}

	return 0;
}