#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int countDigits(int num)
{
	int count = 0;

	for (int i = 3; i >= 0; i--)
	{
		int tens = pow(10, i);
		int digit = num / tens;
		if (digit == 3 || digit == 1 || digit == 6)
		{
			count++;
			num -= digit * tens;
		}
		else if (digit > 0)
		{
			num -= digit * tens;
		}
	}

	return count;
}

int main()
{
	int n;
	scanf("%d", &n);

	int count = 0;

	for (int i = n; i > 0; i--)
	{
		// printf("%d: %d\n", i, countDigits(i));
		count += (countDigits(i));
	}

	printf("%d", count);

	return 0;
}