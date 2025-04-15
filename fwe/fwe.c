#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	int i, status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t pid;
	pid_t my_pid;
	extern char **environ;


	my_pid = getppid();
	printf("PPID: %d\n", my_pid);

	for(i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (pid == 0)
		{
			my_pid = getpid();
			printf("PID: %d\n", my_pid);

			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Error:");
			}
		}

		else
		{
			wait(&status);
		}

	}

	return (0);
}
