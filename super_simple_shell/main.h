#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *str, const char *delim);
pid_t fork(void);
pid_t wait(int *status);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strcpy(char *dest, char *src);
char **stock_args(char *line);
int is_delim(char c, const char *delim);
char *_strdup(char *str);
int main(int ac, char **av, char **env);
int execute(char **argv, char **env);
char find_command(char *cmd, char **env);
int _strncmp(char *s1, char *s2, size_t n);

#endif
