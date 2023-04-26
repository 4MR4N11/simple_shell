#include "main.h"

/**
 * builtin - print the current environment
 *
 * Return: none
 */
void builtin(void)
{
	char **ev;
	char *tmp;
	int count = 0;
	int i, j;

	for (ev = environ; *ev != NULL; ev++)
	{
		count++;
	}

	for (i = 0; i < count -1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (_strcmp(environ[i], environ[j]) > 0)
			{
				tmp = environ[i];
				environ[i] = environ[j];
				environ[j] = tmp;
			}
		}
	}

	for (ev = environ; *ev != NULL; ev++)
	{
		write(STDOUT_FILENO, *ev, _strlen(*ev));
		write(STDOUT_FILENO, "\n", 1);
	}
}
