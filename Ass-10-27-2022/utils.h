#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>

void clrscr()
{
	printf("\e[1;1H\e[2J");
}

void printInt(int n)
{
	printf("%d", n);
}

void scanInt(int *n)
{
	scanf("%d%*c", n);
}

void printString(char *str)
{
	printf("%s", str);
}

void getLine(char *str)
{
	scanf("%[^\n]%*c", str);
}

void swapString(char string1[100], char string2[100])
{
	char temp[100] = "";
	strcpy(temp, string1);
	strcpy(string1, string2);
	strcpy(string2, temp);
}

bool str1Bigger(char *string1, char *string2)
{
	int minLength = (strlen(string1) < strlen(string2) ? strlen(string1) : strlen(string2));
	for (size_t i = 0; i < minLength; i++)
	{
		if (string1[i] > string2[i])
		{
			return false;
		}
	}
	return true;
}

void sortArrayDesc(char nameArr[100][100], char numberArr[100][100], char addressArr[100][100], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i; j < length - i - 1; j++)
		{

			if (strcmp(nameArr[j], nameArr[j + 1]) < 0)
			{
				// printf("swapped, i: %d\n", i);
				swapString(nameArr[j], nameArr[j + 1]);
				swapString(numberArr[j], numberArr[j + 1]);
				swapString(addressArr[j], addressArr[j + 1]);
				// for (int k = 0; k < length; k++)
				// {
				// 	printf("%s\n", nameArr[k]);
				// }
				// puts("");
			}
		}
	}
}

void sortArrayAsc(char nameArr[100][100], char numberArr[100][100], char addressArr[100][100], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{

			if (strcmp(nameArr[j], nameArr[j + 1]) > 0)
			{
				// printf("swapped, i: %d\n", i);
				swapString(nameArr[j], nameArr[j + 1]);
				swapString(numberArr[j], numberArr[j + 1]);
				swapString(addressArr[j], addressArr[j + 1]);
				// for (int k = 0; k < length; k++)
				// {
				// 	printf("%s\n", nameArr[k]);
				// }
				// puts("");
			}
		}
	}
}

int searchEntry(char nameArr[100][100], int left, int right, char *name)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;
		// printf("left: %d\nright: %d\n\n", left, right);

		if (strcmp(name, nameArr[mid]) == 0)
		{
			return mid;
		}
		else if (strcmp(name, nameArr[mid]) > 0)
		{
			return searchEntry(nameArr, left, mid - 1, name);
		}
		else
		{
			return searchEntry(nameArr, mid - 1, right, name);
		}
	}

	return -1;
}

#endif
