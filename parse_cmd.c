#include "main.h"

/**
 * _strcmp -> function that compares two strings
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: nothing
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	int cmp = 0;

	while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			cmp = (s1[i] - s2[i]);
			break;
		}
		i++;
	}
	return (cmp);
}

/**
 * words_counter - count words in a string
 * @str: string
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
	char *tmp;
	int cmd_len = _strlen(args->cmd[0]);
	int j = 0;

	while (args->path[j])
	{
		tmp = malloc(sizeof(char) * cmd_len + _strlen(args->path[j]) + 1);
		if (!tmp)
		{
			free(args->cmd);
			free(args->buff);
			perror(args->av[0]);
			exit(EXIT_FAILURE);
		}
		_strcpy(tmp, args->path[j]);
		_strcat(tmp, args->cmd[0]);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			args->check = 1;
			args->cmd[0] = tmp;
			return;
		}
		free(tmp);
		j++;
	}
	if (_strncmp(args->cmd[0], "./", 2) == 0)
	{
		if (access(args->cmd[0], F_OK) == 0)
		{
			args->check = 1;
			return;
		}
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
			free(args->cmd);
			args->cmd = NULL;
		}
		args->words = words_counter(args->buff, 1);
		if (!args->words)
		{
			return;
		}
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
		path_cmd_join(args);
	}
}

/**
 * split_path - Splits the PATH environment variable into an array of paths.
 * @args: A pointer to a struct of type args_t.
 */
void split_path(args_t *args)
{
	int i = 0, j = 0, words;
	char *tmp;

	if (!args->path)
	{
		while (args->env[i] != NULL)
		{
			if (_strncmp(args->env[i], "PATH", 4) == 0)
			{
				words = words_counter(args->env[i] + 5, 0);
				args->path = malloc(sizeof(char *) * words + 1);
				tmp = strtok(args->env[i] + 5, ":");
				args->path[0] = malloc(sizeof(char) * _strlen(tmp) + 2);
				_strcpy(args->path[0], tmp);
				_strcat(args->path[0], "/");
				while (++j < words)
				{
					tmp = strtok(NULL, ":");
					args->path[j] = malloc(sizeof(char) * _strlen(tmp) + 2);
					_strcpy(args->path[j], tmp);
					_strcat(args->path[j], "/");
				}
				args->path[words] = NULL;
			}
			i++;
		}
	}
}
