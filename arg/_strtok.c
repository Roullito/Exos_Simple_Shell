#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int is_delim(char c, const char *delim)
{
    while (*delim)
    {
        if (*delim == c)
            return 1;
        delim++;
    }
    return 0;
}

char *_strtok(char *str, const char *delim)
{
    static char *current;
    char *token;

    if (str != NULL)
    {
        current = str;
    }

    while (*current != '\0' && is_delim(*current, delim))
    {
        current++;
    }

    if (*current == '\0')
        return (NULL);

    token = current;

    while(*current != '\0' && !is_delim(*current, delim))
        current++;

    if (*current != '\0')
    {
        *current = '\0';
        current++;
    }

    return (token);
}
