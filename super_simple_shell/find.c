#include "main.h"

char find_command(char *cmd, char **env)
{
	size_t i;

	if (_strncmp(env[i], "PATH=", 5) == 0)
	{
		_strtok(env[i], ":");
	}
}
