#include "main.h"

/**
 * words_counter - count words in a string
 * @str: string
 * @c: 1 if the string is a command, 0 if it's a path
 * Return: number of words
*/

int words_counter(char *str, int c)
{
	int words;
	int i;

	i = 0;
	words = 0;
	if (c == 1)
	{
		while (str[i] && str[i] != '\n')
		{
			while ((str[i] && str[i] != '\n') && (str[i] == 32 || str[i] == '\t'))
				i++;
			if ((str[i] && str[i] != '\n') && str[i] != ' ' && str[i] != '\t')
				words++;
			while ((str[i] && str[i] != '\n') && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	else
	{
		while (str[i])
		{
			while ((str[i]) && (str[i] == ':'))
				i++;
			if ((str[i]) && str[i] != ':')
				words++;
			while ((str[i]) && str[i] != ':')
				i++;
		}
	}
	return (words);
}

/**
 * path_cmd_join - joins the command with each directory in the path
 * @args: pointer to a struct containing command and path information
 *
 * Return: void
 */
void path_cmd_join(args_t *args)
{
	int cmd_len = _strlen(args->cmd[0]);
	int j = 0;

	if (access(args->cmd[0], F_OK) == 0)
	{
		args->check = 1;
		return;
	}
	while (args->path[j])
	{
		args->tmp = malloc(sizeof(char) * cmd_len + _strlen(args->path[j]) + 1);
		if (!args->tmp)
		{
			free_all(args);
			perror(args->av[0]);
			exit(EXIT_FAILURE);
		}
		_strcpy(args->tmp, args->path[j]);
		_strcat(args->tmp, args->cmd[0]);
		if (access(args->tmp, F_OK) == 0)
		{
			args->check = 1;
			args->cmd[0] = args->tmp;
			return;
		}
		errno = 0;
		free(args->tmp);
		args->tmp = NULL;
		j++;
	}
	if (_strncmp(args->cmd[0], "./", 2) == 0)
	{
		if (access(args->cmd[0], F_OK) == 0)
		{
			args->check = 1;
			return;
		}
		errno = 0;
	}
	args->check = 0;
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
			free(args->tmp);
			free(args->cmd);
			args->tmp = NULL;
			args->cmd = NULL;
		}
		args->words = words_counter(args->buff, 1);
		if (!args->words)
			return;
		args->cmd = malloc(sizeof(char *) * (args->words + 1));
		if (!args->cmd)
		{
			free_all(args);
			perror(args->av[0]);
			exit(EXIT_FAILURE);
		}
		args->cmd[0] = strtok(args->buff, " \n\t");
		while (++i < args->words)
			args->cmd[i] = strtok(NULL, " \n\t");
		args->cmd[args->words] = NULL;
		path_cmd_join(args);
	}
}

/**
 * malloc_error - prints an error message and exits the program
 * @args: arguments
*/

void malloc_error(args_t *args)
{
	free_all(args);
	perror(args->av[0]);
	exit(EXIT_FAILURE);
}

/**
 * split_path - Splits the PATH environment variable into an array of paths.
 * @args: A pointer to a struct of type args_t.
 */
void split_path(args_t *args)
{
	int i = 0, j = -1, words;
	char *tmp;

	if (!args->path)
	{
		while (args->env[i] != NULL)
		{
			if (_strncmp(args->env[i], "PATH", 4) == 0)
			{
				words = words_counter(args->env[i] + 5, 0);
				args->path = malloc(sizeof(char *) * (words + 1));
				if (!args->path)
					malloc_error(args);
				tmp = strtok(args->env[i] + 5, ":");
				args->path[++j] = malloc(sizeof(char) * (_strlen(tmp) + 2));
				if (!args->path[j])
					malloc_error(args);
				_strcpy(args->path[j], tmp);
				_strcat(args->path[j], "/");
				while (++j < words)
				{
					tmp = strtok(NULL, ":");
					args->path[j] = malloc(sizeof(char) * (_strlen(tmp) + 2));
					if (!args->path[j])
					{
						free_all(args);
						perror(args->av[0]);
						exit(EXIT_FAILURE);
					}
					_strcpy(args->path[j], tmp);
					_strcat(args->path[j], "/");
				}
				args->path[words] = NULL;
			}
			i++;
		}
	}
}
