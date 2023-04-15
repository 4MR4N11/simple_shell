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
} args_t;

void execute(args_t *args);
int words_counter(char *str);
void split_cmd(args_t *args);

#endif
