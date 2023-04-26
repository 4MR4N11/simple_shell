#include "main.h"

/**
 * cmd_fullpath - checks if the command is a full path
 * @args: pointer to a struct containing command and path information
 * Return: 0 if it is a full path, 1 otherwise
*/
int cmd_fullpath(args_t *args)
{
	int check = 0, i = 0, j = 0;

	if (access(args->cmd_args[0], F_OK) == 0)
	{
		while (args->path[j])
		{
			i = 0;
			while (args->cmd_args[0][i])
			{
				if (args->cmd_args[0][i] == '/' && args->path[j][i + 1] == '\0')
				{
					check = 1;
					break;
				}
				if (args->cmd_args[0][i] != args->path[j][i])
				{
					check = 0;
					break;
				}
				i++;
			}
			if (check == 1)
			{
				args->cmd = _strdup(args->cmd_args[0]);
				args->check = 1;
				return (0);
			}
			j++;
		}
	}
	return (1);
}
