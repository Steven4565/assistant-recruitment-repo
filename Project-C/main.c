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

#include "globals.c"
#include "globals.h"

int main()
{

	menuLoop();
	// startEventLoop(&gameLoop); // this is for starting the main event
}