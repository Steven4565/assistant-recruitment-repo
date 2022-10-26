#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <unistd.h>

int msec = 0;
int FRAME_DELAY = 20;
bool endGame = false;

void clrscr()
{
	printf("\e[1;1H\e[2J");
}

char getInput()
{
	if (kbhit())
	{
		return getch();
	}
	else
	{
		return ' ';
	}
}

void startEventLoop(void (*logic)())
{
	clock_t before = clock();
	while (!endGame)
	{
		clock_t difference = clock() - before;
		msec = difference * 1000 / CLOCKS_PER_SEC;
		if (msec >= FRAME_DELAY)
		{
			before = clock();

			// run logic here
			logic();
		}
	}
}

void logic()
{
	char input = getInput();
	clrscr();
	printf("input: %c", input);
}

int main()
{
	startEventLoop(&logic);
}