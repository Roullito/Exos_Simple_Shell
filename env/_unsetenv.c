#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
    int i,j;
    size_t len_name;

    if (name == NULL || name[0] == '\0')
    {
        return (-1);
    }

    len_name = strlen(name);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, len_name) == 0
            && environ[i][len_name] == '=')
        {
            for (j = i; environ[j] != NULL; j++)
                environ[j] = environ[j + 1];

            return (0);
        }
    }
    return (-1);
}

int main(void)
{
    char **env;

    printf("Avant unset:\n");
    for (env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, "PATH=", 5) == 0)
            printf("%s\n", *env);
    }

    _unsetenv("PATH");

    printf("Après unset:\n");
    for (env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, "PATH=", 5) == 0)
            printf("%s\n", *env);
    }

    return (0);
}
