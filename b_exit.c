#include "main.h"

/**
 * b_exit - exits the shell
 * @args: The arguments struct
 */

void b_exit(args_t *args)
{
	errno = args->errno_value;
	free_all(args);
	fflush(stdout);
	_exit(errno);
}
