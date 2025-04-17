#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

typedef struct path_node
{
	char *dir;
	struct  path_node *next;
} path_node_t;

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
	char *path, *temp, *buf;
	path_node_t *new_node, *head = NULL, *current = NULL, *tmp;

	path = _getenv("PATH");
	if (path == NULL)
		return (1);

	temp = path;
	temp = strtok(path, ":");
	while(temp)
	{
		new_node = malloc(sizeof(path_node_t));
		if (new_node == NULL)
			return (1);

		new_node->dir = strdup(temp);
		new_node->next = NULL;
		if (head == NULL)
			head = new_node;
		else
			current->next = new_node;
		current = new_node;
		printf("%s\n", new_node->dir);
		temp = strtok(NULL, ":");
	}

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->dir);
		free(tmp);
	}

	return (0);
}

