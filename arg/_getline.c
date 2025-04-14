#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

ssize_t _getline(char **restrict lineptr, size_t *restrict n,
	FILE *restrict stream)
{
	size_t r;

	if (lineptr == NULL || n == NULL || stream == NULL)
    	return -1;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128; // taille par défaut
		*lineptr = malloc(*n);

		if (*lineptr == NULL)
			return -1;
	}

	r = read(fileno(stream), *lineptr, *n);

	if (r <= 0)
		return (-1);

	return (r);
}
