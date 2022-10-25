#include <stdio.h>

int main()
{

	int test;
	scanf("%d", &test);

	for (int t = 0; t < test; t++)
	{
		int choc, students;
		scanf("%d %d", &choc, &students);
		students++;
		printf("%d\n", ((choc >= students) ? 0 : students - choc));
	}

	return 0;
}