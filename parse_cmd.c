#include "main.h"

/**
 * words_counter - count words in a string
 * @str: string
 * Return: number of words
*/

int words_counter(char *str)
{
	int words;
	int i;

	i = 0;
	words = 0;
	while (str[i] && str[i] != '\n')
	{
		while ((str[i] && str[i] != '\n') && (str[i] == 32 || str[i] == '\t'))
			i++;
		if ((str[i] && str[i] != '\n') && str[i] != ' ' && str[i] != '\t')
			words++;
		while ((str[i] && str[i] != '\n') && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (words);
}

/**
 * split_cmd - split the input into words
 * @args: arguments
*/

void split_cmd(args_t *args)
{
	int i;

	i = 0;
	if (args->buff)
	{
		if (args->cmd)
		{
			free(args->cmd);
			args->cmd = NULL;
		}
		args->words = words_counter(args->buff);
		args->cmd = malloc(sizeof(char *) * (args->words + 1));
		if (!args->cmd)
		{
			free(args->buff);
			perror(args->av[0]);
			exit(EXIT_FAILURE);
		}
		args->cmd[0] = strtok(args->buff, " \n\t");
		while (++i < args->words)
			args->cmd[i] = strtok(NULL, " \n\t");
		args->cmd[args->words] = NULL;
	}
}
