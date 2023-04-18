#include "main.h"

/**
 * b_exit - exits the shell
 * @args: The arguments struct
 */

void b_exit(args_t *args)
{
	free_all(args);
	fflush(stdout);
	_exit(0);
}
