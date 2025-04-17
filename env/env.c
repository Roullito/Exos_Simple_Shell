#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

int main(void)
{
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }

    return (0);
}
