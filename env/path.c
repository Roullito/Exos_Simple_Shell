#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
    int i, j;

    for (i = 0; environ[i] != NULL; i++)
    {
        for (j =0; name[j] != '\0'; j++)
        {
            if (environ[i][j] != name[j])
                break;
        }
        if (name[j] == '\0' && environ[i][j] == '=')
        {
            return (&environ[i][j + 1]);
        }
    }

    return (NULL);
}

int main(void)
{
    char *path = _getenv("PATH");
    char *temp;

    if (path == NULL)
        return (1);

    temp = strtok(path, ":");
    while(temp)
    {
        printf("%s\n", temp);
        temp = strtok(NULL, ":");
    }

    return (0);
}
