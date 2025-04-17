#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
    int i, count = 0;
    char *new_name, **new_environ;
    size_t len_name;

    if (name == NULL || value == NULL)
        return (-1);
    len_name = strlen(name);
    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, len_name) == 0
            && environ[i][len_name] == '=')
        {
            if (!overwrite)
                return (0);

            new_name = malloc(len_name + strlen(value) + 2);
            if (!new_name)
                return (-1);
            sprintf(new_name, "%s=%s", name, value);
            free(environ[i]);
            environ[i] = new_name;
            return (0);
        }
        count++;
    }
    new_name = malloc(len_name + strlen(value) + 2);
    if (!new_name)
        return (-1);
    sprintf(new_name, "%s=%s", name, value);

    new_environ = malloc(sizeof(char *) * (count + 2));
    if (!new_environ)
    {
        free(new_name);
        return (-1);
    }
    for (i = 0; i < count; i++)
    {
        new_environ[i] = environ[i];
    }
    new_environ[count] = new_name;
    new_environ[count + 1] = NULL;
    environ = new_environ;

    return (0);
}

int main(void)
{
    char *var;

    printf("Avant _setenv:\n");
    var = getenv("MYVAR");
    if (var)
        printf("MYVAR = %s\n", var);
    else
        printf("MYVAR non défini\n");

    /* Test de création */
    _setenv("MYVAR", "42", 0);

    printf("\nAprès _setenv (création):\n");
    var = getenv("MYVAR");
    if (var)
        printf("MYVAR = %s\n", var);

    /* Test de modification sans overwrite */
    _setenv("MYVAR", "NON", 0);
    printf("\nAprès _setenv (overwrite=0):\n");
    printf("MYVAR = %s\n", getenv("MYVAR"));

    /* Test de modification avec overwrite */
    _setenv("MYVAR", "1337", 1);
    printf("\nAprès _setenv (overwrite=1):\n");
    printf("MYVAR = %s\n", getenv("MYVAR"));

    return (0);
}
