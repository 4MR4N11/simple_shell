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
	if (args->tmp)
	{
		free(args->tmp);
		args->tmp = NULL;
	}
	if (args->buff)
	{
		free(args->buff);
		args->buff = NULL;
	}
	if (args->cmd)
	{
		free(args->cmd);
		args->cmd = NULL;
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
	if (_strcmp(args->cmd[0], "exit") == 0)
	{
		b_exit(args);
		return (1);
	}
	return (0);
}
