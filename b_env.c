#include "main.h"

/**
 * builtin - print the current environment
 *
 * Return: none
 */
void builtin(void)
{
	extern char **environ;
	char **ev;

	for (ev = environ; *ev != NULL; ev++)
	{
		write(STDOUT_FILENO, *ev, _strlen(*ev));
		write(STDOUT_FILENO, "\n", 1);
	}
}
