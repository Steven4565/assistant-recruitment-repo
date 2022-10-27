#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

#include "config.h"

#include "utils/printUtils.h"
#include "utils/inputUtils.h"
#include "utils/eventTimer.h"

#include "events/eventStruct.h"
#include "events/events.c"
#include "events/events.h"
#include "events/handlers/enemyHandler.h"

#include "menus/mainMenu.h"

#include "globals.h"

#include <unistd.h>

int main()
{
	if (DEBUG)
	{
		char cwd[1000];
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printf("Current working dir: %s\n", cwd);
		}
		else
		{
			perror("getcwd() error");
		}
		puts(cwd);
		getchar();
	}

	menuLoop();
	// startEventLoop(&gameLoop); // this is for starting the main event
}