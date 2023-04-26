#include "main.h"

/**
 * error_message - prints error message
 * @args: arguments
*/

void error_message(args_t *args)
{
	write(2, args->cmd_args[0], _strlen(args->cmd_args[0]));
	write(2, ": Permission denied\n", 20);
}
/**
 * execute - execute a command
 * @args: arguments
*/

void execute(args_t *args)
{
	pid_t id;
	int status;
	int error;

	args->errno_value = 0;
	id = fork();
	if (id == -1)
	{
		perror("Error fork:");
		free_all(args);
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		error = execve(args->cmd, args->cmd_args, args->env);
		if (error == -1)
		{
			write(2, args->av[0], _strlen(args->av[0]));
			write(2, ": ", 2);
			print_number(args->input_count);
			write(2, ": ", 2);
			if (_strncmp(args->cmd_args[0], "./", 2) == 0)
				error_message(args);
			else
				perror(args->cmd_args[0]);
			free_all(args);
			exit(126);
		}
	}
	if (id > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
			args->errno_value = WEXITSTATUS(status);
	}
}
