#include "main.h"

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
	}
}
