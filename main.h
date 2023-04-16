#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * struct args - all used arguments and variables.
 * @cmd: command with arguments
 * @env: environment variables
 * @buff: buffer to read
 * @len: length of buffer
 * @read_check: read check value
 * @av: the arguments
 * @words: number of words in the command
 */
typedef struct args
{
	char **cmd;
	char **env;
	char *buff;
	size_t len;
	ssize_t read_check;
	char **av;
	int words;
	char **path;
} args_t;

void execute(args_t *args);
int words_counter(char *str, int c);
void split_cmd(args_t *args);
void split_path(args_t *args);
int _strncmp(char *s1, char *s2, int n);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
