#include <stdio.h>
#include <stdbool.h>

int numMaps[100] = {1000, 600, 100, 50, 10, 9, 6, 1};
const char *charMaps = "MRCLXNSO";

bool checkNumber(int num)
{
	if (num == 41)
	{
		printf("GH\n");
		return true;
	}

	for (int i = 7; i >= 0; i--)
	{
		if (numMaps[i] == num)
		{
			printf("%c\n", charMaps[i]);
			return true;
		}
	}

	return false;
}

int main()
{

	int n;
	scanf("%d", &n);

	bool continueLooping = true;

	while (continueLooping)
	{
		// check if there if n - numMaps = 0
		if (checkNumber(n))
		{
			return 0;
		}

		// pick the last one
		for (int i = 0; i < 8; i++)
		{
			if (n - numMaps[i] > 0)
			{
				n -= numMaps[i];
				printf("%c", charMaps[i]);
				break;
			}
			else if (n - numMaps[i] == 0)
			{
				continueLooping = false;
			}
		}
	}

	return 0;
}