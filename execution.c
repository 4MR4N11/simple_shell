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
			write(2, args->av[0], _strlen(args->av[0]));
			write(2, ": ", 2);
			print_number(args->input_count);
			write(2, ": ", 2);
			perror(args->cmd[0]);
			free_all(args);
			exit(errno);
		}
	}
	if (id > 0)
	{
		wait(&status);
		if (!isatty(STDIN_FILENO))
		{
			free_all(args);
			exit(0);
		}
		fflush(stdout);
	}
}
