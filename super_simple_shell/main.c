#include "main.h"

/**
 * main - Entry point of our custom shell
 * @ac: Argument count (unused)
 * @av: Argument vector (unused)
 * @env: Environment variables
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t r;
	char **argv;
	int i;

	(void)ac;
	(void)av;

	while (1)
	{
		write(1, "$ ", 2);

		r = _getline(&line, &len, 0);
		if (r == -1)
		{
			free(line);
			break;
		}

		if (r > 0 && line[r - 1] == '\n')
			line[r - 1] = '\0';

		argv = stock_args(line);
		if (argv != NULL)
		{
			execute(argv, env);

			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
		}
	}

	free(line);
	return (0);
}
