#include <stdio.h>
#include <math.h>

void printChars(char char_, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%c", char_);
	}
}
int main()
{

	int n;
	scanf("%d", &n);
	int diamond = n - 2;

	printChars('*', n);
	puts("");

	// middle
	for (int i = 1; i < n - 1; i++)
	{
		// left border
		printf("%c", '*');

		// make a diamond with n-2 dimensions here
		if (i != 0 && i != n - 1)
		{
			for (int j = 0; j < diamond; j++)
			{
				int y = i - 1;
				int x = j;

				int coef = floor(diamond / 2);

				if (x + y == coef || x - y == coef || y - x == coef || y + x == coef + diamond - 1)

				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}

			// right border
			printf("%c", '*');
			puts("");
		}
	}

	printChars('*', n);
	puts("");

	return 0;
}
