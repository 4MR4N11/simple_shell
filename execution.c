#include "main.h"

/**
 * error_msg - prints error message
 * @args: arguments
 * @fd_checker: file descriptor checker
 * Return: 1 if error, 0 if not
*/
int error_msg(args_t *args, int fd_checker)
{
	if (fd_checker >= 0 || access(args->cmd, X_OK) != 0)
	{
		args->errno_value = 126;
		write(2, args->av[0], _strlen(args->av[0]));
		write(2, ": ", 2);
		print_number(args->input_count);
		write(2, ": ", 2);
		write(2, args->cmd_args[0], _strlen(args->cmd_args[0]));
		write(2, ": Permission denied\n", 20);
		free_all(args);
		return (1);
	}
	return (0);
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
	int fd_checker;

	args->errno_value = 0;
	if (access((args->cmd), F_OK) == 0)
	{
		fd_checker = open(args->cmd, __O_DIRECTORY);
		if (fd_checker < 0 && access(args->cmd, X_OK) == 0)
			id = fork();
		if (error_msg(args, fd_checker))
			return;
	}
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
