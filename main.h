#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

typedef struct args{
	char **cmd;
	char **env;
	char **av;
	int words;
} args_t;

void execute(args_t *args);

#endif