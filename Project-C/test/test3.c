#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1000
#define DEBUG 0

int main()
{
	FILE *textfile;
	char ch;

	if (DEBUG)
	{
		char cwd[PATH_MAX];
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printf("Current working dir: %s\n", cwd);
		}
		else
		{
			perror("getcwd() error");
			return 1;
		}
	}

	textfile = fopen("lobby.txt", "r");
	if (textfile == NULL)
		return 1;

	while ((ch = fgetc(textfile)) != EOF)
	{
		putchar(ch);
	}

	fclose(textfile);
	return 0;
}