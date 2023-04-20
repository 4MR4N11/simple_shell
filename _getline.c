#include "main.h"

/**
 * malloc_or_realloc - malloc or realloc a buffer
 * @line: pointer to a string
 * @i: index
 * @n: size of the buffer
 * Return: 0 on success, -1 on failure
*/

int malloc_or_realloc(char **line, ssize_t i, size_t **n)
{
	if (i == 0)
	{
		*line = malloc(BUFFSIZE);
		if (*line == NULL)
			return (-1);
	}
	else if (i >= BUFFSIZE)
	{
		char *new_line = _realloc(*line, BUFFSIZE, BUFFSIZE * 2);

		if (new_line == NULL)
		{
			free(*line);
			return (-1);
		}
		*line = new_line;
		**n = BUFFSIZE * 2;
	}
	return (0);
}

/**
 * _getline - reads an entire line from a file descriptor
 * @lineptr: pointer to a string
 * @n: size of the buffer
 * @stream: file descriptor
 * Return: number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char c = '\0';
	int rread;
	static ssize_t i;
	char *line = NULL;

	i = 0;
	if (!stream || stream != stdin)
		return (-1);
	*n = 120;
	while (c != '\n')
	{
		rread = read(STDIN_FILENO, &c, 1);
		if (rread <= 0)
			break;
		if (malloc_or_realloc(&line, i, &n) == -1)
			return (-1);
		line[i++] = c;
	}
	if (i > 0 || c == '\n')
	{
		line[i] = '\0';
		*lineptr = line;
		if (i > BUFFSIZE)
			*n = i;
		return (i);
	}
	if (rread == -1)
		return (-1);
	return (-1);
}
