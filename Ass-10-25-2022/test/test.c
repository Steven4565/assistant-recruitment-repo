#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int getRandom(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

int main()
{
	srand(time(NULL));

	char *input = "Shanie Laurentia";
	char str[1000] = "";
	for (int i = 0; i < strlen(input); i++)
	{
		char char_ = toupper(input[i]);
		if (char_ >= 'A' && char_ <= 'Z')
			strncat(str, &char_, 1);
	}

	int length = strlen(str);
	int randChoice[4];
	for (int i = 0; i < 4; i++)
	{
		randChoice[i] = getRandom(0, length - i);
		printf("rand: %d\n", randChoice[i]);
	}

	char output[5];
	output[5] = '\0';
	for (int i = 0; i < 4; i++)
	{
		int nthChar = randChoice[i];
		int index = 0;
		for (int j = 0; j < length; j++)
		{

			if (index == nthChar)
			{
				output[i] = str[j];
				str[j] = '-';
				break;
			}

			if (str[j] != '-')
			{
				index++;
			}
		}
	}

	printf("result: %s\n", output);

	return 0;
}