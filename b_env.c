#include "main.h"

/**
 * builtin - print the current environment
 *
 * Return: none
 */
void builtin(void)
{
	int i;

	if (!environ)
		return;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
