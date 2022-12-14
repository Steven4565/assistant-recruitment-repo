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
#include "../utils/gameUtils.h"

#include "../dataStructures/hashTable.h"

void insert()
{
	char name[100];
	int age;
	int weight;
	char gender[10];
	char code[50] = "";

	getInputString("Input name (>=2 char)", nameValidator, name);
	getInputInt("Input age (>= 10 yo)", ageValidator, &age);
	getInputInt("Input weight (>= 30kg)", weightValidator, &weight);
	getInputString("Input gender (male/female insensitive)", genderValidator, gender);

	getCode(name, age, weight, gender, code);

	printf("\nhash key: %d\n", getHash(code));

	pushHashTable(hashTable, name, age, weight, gender, code);
	puts("Successfully inserted");
	getEnter();
}

void view()
{
	printf("| %-25s | %-5s | %-7s | %-10s | %-15s |\n", "Name", "Age", "Weight", "Gender", "Code");
	printf("------------------------------------------------------------------------------\n");
	printHashTable(hashTable);
	getEnter();
}
void delete ()
{
	printf("| %-25s | %-5s | %-7s | %-10s | %-15s |\n", "Name", "Age", "Weight", "Gender", "Code");
	printf("------------------------------------------------------------------------------\n");
	printHashTable(hashTable);
	puts("Enter the code you want to delete");

	char code[50];
	getInputString("Enter the code you want to delete", codeValidator, code);

	popHashTable(hashTable, code);

	puts("Successfully deleted entry");
	getEnter();
}

bool menuPage()
{
	clrscr();
	puts("BSGYM");
	puts("===========");

	char *menus[] = {"Insert membership", "View membership", "Delete membership", "Exit"};
	int input;
	getInputRange(menus, 4, 1, 4, false, &input);

	if (input == 4)
		return false;

	switch (input)
	{
	case 1:
		insert();
		break;
	case 2:
		view();
		break;
	case 3:
		delete ();
		break;
	default:
		break;
	}

	return true;
}

#endif