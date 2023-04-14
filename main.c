#include "main.h"

int words_counter(char *str)
{
	int words;
	int i;

	i = 0;
	words = 0;
	while (str[i] && str[i] != '\n')
	{
		while ((str[i] && str[i] != '\n') && (str[i] == 32 || str[i] == '\t'))
			i++;
		if ((str[i] && str[i] != '\n') && str[i] != ' ' && str[i] != '\t')
			words++;
		while ((str[i] && str[i] != '\n') && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (words);
}

int	main(int ac, char **av, char **env)
{
	char *buff = NULL;
	size_t len;
	ssize_t read_check;
	args_t args;
	int i;

	i = 0;
	args.cmd = NULL;
	args.env = env;
	args.av = av;
	while (1)
	{
		printf("\033[38;2;0;63;92msimple_shell$\033[0m ");
		read_check = getline(&buff, &len, stdin);
		if (read_check == -1)
		{
			free(buff);
			if (!errno)
				exit(EXIT_SUCCESS);
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		if(buff)
		{
			if (args.cmd)
			{
				i = 0;
				free(args.cmd);
				args.cmd = NULL;
			}
			args.words = words_counter(buff);
			args.cmd = malloc(sizeof(char *) * args.words);
			i = 0;
			args.cmd[0] = strtok(buff, " \n\t");
			while(++i < args.words)
				args.cmd[i] = strtok(NULL, " \n\t");
		}
		if (!args.cmd)
		{
			free(buff);
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		execute(&args);
	}
	return (0);
}