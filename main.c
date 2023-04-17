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

	args.input_count = 1;
	if (ac == 1)
	{
		args.buff = NULL;
		args.cmd = NULL;
		args.path = NULL;
		args.env = env;
		args.av = av;
		while (1)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\033[38;2;0;63;92msimple_shell$\033[0m ", 33);
			args.read_check = getline(&args.buff, &args.len, stdin);
			if (args.read_check == -1)
			{
				free(args.buff);
				if (!errno)
					exit(EXIT_SUCCESS);
				perror(av[0]);
				exit(EXIT_FAILURE);
			}
			split_path(&args);
			split_cmd(&args);
			if (args.check)
				execute(&args);
			else
			{
				if (args.buff[0] != '\n')
				{
					write(2, av[0], _strlen(av[0]));
					write(2, ": ", 2);
					print_number(args.input_count);
					write(2, ": ", 2);
					write(2, args.cmd[0], _strlen(args.cmd[0]));
					write(2, ": not found\n", 12);
				}
			}
			args.input_count++;
		}
	}
	printf("Usage: ./hsh\n");
	return (EXIT_FAILURE);
}
