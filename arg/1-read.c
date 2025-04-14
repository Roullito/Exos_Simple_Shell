#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t read = 0;

	while (lineptr == NULL)
	{
		printf("$ ");
		read = _getline(&lineptr, &n, stdin);

		if (read != -1)
		{
			printf("you wrote: %s", lineptr);
			free(lineptr);
			lineptr = NULL;
		}

		else
			break;
	}

	return (0);
}
