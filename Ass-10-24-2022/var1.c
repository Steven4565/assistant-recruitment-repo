#include <stdio.h>

int main()
{

	int test;
	scanf("%d", &test);
	for (int t = 0; t < test; t++)
	{
		int a, x, y, z;
		scanf("%d %d %d %d", &a, &x, &y, &z);
		puts(((a >= x && a < y && a % z == 0) ? "Eligible\n" : "Not Eligible\n"));
	}

	return 0;
}