#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define BUFFSIZE 120
/**
 * struct args - all used arguments and variables.
 * @cmd_args: command with arguments
 * @env: environment variables
 * @buff: buffer to read
 * @len: length of buffer
 * @read_check: read check value
 * @av: the arguments
 * @words: number of words in the command
 * @path: path directories
 * @check: check value for execve
 * @input_count: number of inputs
 * @cmd: command with full path
 * @errno_value: errno value to exit
 */
typedef struct args
{
	char **cmd_args;
	char **env;
	char *buff;
	size_t len;
	ssize_t read_check;
	char **av;
	int words;
	char **path;
	int check;
	int input_count;
	char *cmd;
	int errno_value;
} args_t;

void execute(args_t *args);
int words_counter(char *str, int c);
void split_cmd(args_t *args);
void split_path(args_t *args);
int _strncmp(char *s1, char *s2, int n);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
void print_number(int n);
void path_cmd_join(args_t *args);
void b_exit(args_t *args);
void free_all(args_t *args);
int _strcmp(char *s1, char *s2);
int check_builtin(args_t *args);
void builtin(args_t *args);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strpbrk(const char *str1, const char *str2);
size_t _strspn(const char *str1, const char *str2);
char *_strtok(char *str, const char *delim);
char *_strdup(char *str);

extern char **environ;

#endif
