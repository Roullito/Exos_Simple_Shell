#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void split_string(char *line)
{
    char *mot = _strtok(line, " \n");

    while (mot != NULL)
    {
        printf("mot: %s\n", mot);
        mot = _strtok(NULL, " ");
    }
}

int main(void)
{
    char *line = NULL;
    size_t len = 0;

    printf("$ ");
    getline(&line, &len, stdin);

    split_string(line);

    free(line);
    return 0;
}
