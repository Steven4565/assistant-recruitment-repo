
#include <stdio.h>
#include <conio.h>

int main()
{

	for (int i = 0; i < 1000; i++)
	{
		printf("%d\n", i);
		printf("%d\n", i);
		printf("%d\n", i);
		printf("\e[1;1H\e[2J");
	}

	return 0;
}