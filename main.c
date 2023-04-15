#include "main.h"

/**
 * main - entry point.
 * Description: simple shell.
 * @ac: Number of arguments.
 * @av: The arguments.
 * @env: The environment variables.
 * Return: 1 if ac != 1.
*/

int	main(int ac, char **av, char **env)
{
	args_t args;

	if (ac == 1)
	{
		args.buff = NULL;
		args.cmd = NULL;
		args.env = env;
		args.av = av;
		while (1)
		{
			if (isatty(STDIN_FILENO))
				printf("\033[38;2;0;63;92msimple_shell$\033[0m ");
			args.read_check = getline(&args.buff, &args.len, stdin);
			if (args.read_check == -1)
			{
				free(args.buff);
				if (!errno)
					exit(EXIT_SUCCESS);
				perror(av[0]);
				exit(EXIT_FAILURE);
			}
			split_cmd(&args);
			execute(&args);
		}
	}
	printf("Usage: ./hsh\n");
	return (EXIT_FAILURE);
}
