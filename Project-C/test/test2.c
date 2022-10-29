#include <stdio.h>
#include <conio.h>
#include <unistd.h>

int main()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			usleep(100000);
			printf("%c", 'a');
		}
		printf("\n");
	}

	return 0;
}