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

	puts("Successfully inserted");
	getEnter();
}

void login()
{
}

void regist()
{
}

bool menuPage()
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