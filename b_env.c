#include "main.h"

/**
 * builtin - print the current environment
 * @args: pointer to args_t structure
 *
 * Return: none
 */
void builtin(args_t *args)
{
	char **ev;

	for (ev = args->env; *ev != NULL; ev++)
	{
		write(STDOUT_FILENO, *ev, _strlen(*ev));
		write(STDOUT_FILENO, "\n", 1);
	}
}
