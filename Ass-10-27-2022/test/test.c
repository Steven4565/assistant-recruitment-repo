#include <stdio.h>
#include <string.h>

void getString()
{
}

int main()
{
	char *test = "asdfasdasdf";
	char test2[9] = "asdfasdf";
	char **test3;

	int *testInt = {1, 2, 3, 5};
	printf("sizeof %d\n", sizeof(test));
	printf("sizeof %d\n", sizeof(test2));
	printf("sizeof %d\n", sizeof(**test3));
	printf("sizeof %d\n", sizeof(test));
}