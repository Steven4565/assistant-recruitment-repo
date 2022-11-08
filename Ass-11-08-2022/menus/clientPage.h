#ifndef CLIENT_PAGE_H
#define CLIENT_PAGE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/inputUtils.h"
#include "../utils/outputUtils.h"
#include "../utils/validators.h"
#include "../utils/fileUtils.h"
#include "../utils/utils.h"

bool clientPage()
{
	clrscr();
	puts("MyDramaList");
	puts("===========");
	char *options[] = {"View drama",
										 "add watch later",
										 "watch later",
										 "queue",
										 "watch queue",
										 "logout"};
	int input;
	getInputRange(options, 6, 1, 6, &input);

	if (input == 6)
		return false;

	switch (input)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}

	return true;
}
#endif