#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <unistd.h>

int msec = 0;
int FRAME_DELAY = 20;
int iteration = 0;
bool endGame = false;

void clrscr()
{
	printf("\e[1;1H\e[2J");
}

int main()
{
	clock_t before = clock();
	while (!endGame)
	{
		clock_t difference = clock() - before;
		msec = difference * 1000 / CLOCKS_PER_SEC;
		if (msec >= FRAME_DELAY)
		{
			before = clock();
			iteration++;

			clrscr();
			if (kbhit())
			{
				printf("input:    %c    \n", getch());
			}
			else
			{
				printf("    a   ", iteration);
			}
		}
	}
}