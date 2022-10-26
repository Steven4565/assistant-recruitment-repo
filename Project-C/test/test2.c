#include <stdio.h>
#include <conio.h>

int main()
{
	scanf("%*s");
	while (!kbhit())
	{
		getch();
		printf("Press a key\n");
	}

	return 0;
}