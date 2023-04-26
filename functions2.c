#include "main.h"

/**
 * _strncmp - compares two strings up to n bytes
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, otherwise the difference
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
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if strings are equal, otherwise the difference
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int cmp = 0;

	while ((s1[i] != '\0' || s2[i] != '\0'))
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
 * free_all - Frees all memory allocated
 * @args: The arguments struct
 */

void free_all(args_t *args)
{
	int i;

	i = 0;
	if (args->cmd)
	{
		free(args->cmd);
		args->cmd = NULL;
	}
	if (args->buff)
	{
		free(args->buff);
		args->buff = NULL;
	}
	if (args->cmd_args)
	{
		free(args->cmd_args);
		args->cmd_args = NULL;
	}
	if (args->path)
	{
		while (args->path[i])
		{
			free(args->path[i]);
			args->path[i] = NULL;
			i++;
		}
		free(args->path);
		args->path = NULL;
	}
}

/**
 * check_builtin - Checks if the command is a builtin
 * @args: The arguments struct
 * Return: 1 if it is a builtin, 0 otherwise
*/

int check_builtin(args_t *args)
{
	if (args->cmd_args == NULL)
		return (1);
	if (_strcmp(args->cmd_args[0], "exit") == 0)
	{
		b_exit(args);
		return (1);
	}
	if (_strcmp(args->cmd_args[0], "env") == 0)
	{
		builtin(args);
		return (1);
	}
	return (0);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: pointer to string.
 * Return: On success, function returns a pointer to the duplicated string.
 * It returns NULL if it fails.
 */

char *_strdup(char *str)
{
	char *new;
	int i;

	i = -1;
	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * (_strlen(str) + 1));
	if (!new)
		return (NULL);
	while (str[++i])
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}
