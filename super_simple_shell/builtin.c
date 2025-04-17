#include "main.h"

int handle_builtin(char **argv)
{
	int i;

	if (argv[0] && strcmp(argv[0], "exit") == 0)
	{
		for (i = 0; argv[i]; i++)
			free(argv[i]);

		free(argv);
		return (-1);
	}

	return (0);
}
