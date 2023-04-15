#include "main.h"

/**
 * execute - execute a command
 * @args: arguments
*/

void execute(args_t *args)
{
	pid_t id;
	int status;
	int error;

	id = fork();
	if (id == 0)
	{
		error = execve(args->cmd[0], args->cmd, args->env);
		if (error == -1)
		{
			perror(args->av[0]);
			exit(errno);
		}
	}
	if (id > 0)
	{
		wait(&status);
		if (!isatty(STDIN_FILENO))
		{
			free(args->buff);
			free(args->cmd);
			exit(0);
		}
		fflush(stdout);
	}
}
