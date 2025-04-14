#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>

ssize_t _getline(char **restrict lineptr, size_t *restrict n,
	FILE *restrict stream);
char *_strtok(char *str, const char *delim);
int is_delim(char c, const char *delim);

#endif

