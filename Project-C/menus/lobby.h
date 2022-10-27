#ifndef LOBBY_H
#define LOBBY_H

#include <time.h>
#include <stdio.h>
#include "../utils/eventTimer.h"
#include "../events/eventStruct.h"
#include "../events/events.c"
#include "../events/events.h"
#include "../globals.h"
#include "../utils/printUtils.h"
#include "../utils/inputUtils.h"

void handleLobbyInput(char input)
{
}

void renderLobby()
{
}

void lobbyLoop()
{
	bool runLobby = true;

	char *lobbyMessages;
	renderLobby();

	while (runLobby)
	{
		clrscr();
		renderLobby();
		char input = getch();
	}
}

#endif