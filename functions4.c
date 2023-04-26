#include "main.h"

/**
 * check_set - checks if a character is in a set
 * @c: character to check
 * @set: set of characters
 * Return: 1 if character is in set, otherwise 0
*/
int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strtrim - trims the beginning and end of a string
 * @s1: string to trim
 * @set: set of characters to trim
 * Return: pointer to the trimmed string
 */

char	*_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	len = 0;
	i = 0;
	if (!s1 || !set)
		return (0);
	j = _strlen((char *)s1) - 1;
	while (check_set(s1[i], set))
		i++;
	while (check_set(s1[j], set) == 1 && (j > 0))
		j--;
	len = j - i;
	if (len < 0)
		len = 0;
	str = _substr(s1, i, len + 1);
	return (str);
}

/**
 * _substr - returns a substring of a string
 * @s: string
 * @start: starting index
 * @len: length of substring
 * Return: pointer to the substring
 */

char	*_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)_strlen((char *)s) < start)
		len = 0;
	if (len >= (_strlen((char *)s) - start))
		len = _strlen((char *)s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * trim_path - trims the PATH= from the beginning of the PATH variable
 * @env: pointer to the PATH variable
 * Return: pointer to the trimmed PATH variable
 */

char *trim_path(char *env)
{
	char *path = NULL;

	path = _strtrim(env, "PATH=");
	return (path);
}

/**
 * get_env - gets the index of an environment variable
 * @args: pointer to a struct containing command and path information
 * @path: pointer to the environment variable to search for
 * Return: index of the environment variable, or -1 if not found
*/
int get_env(args_t *args, char *path)
{
	int i, j;

	i = 0;
	while (args->env[i])
	{
		j = 0;
		while (args->env[i][j] && args->env[i][j] != '=')
		{
			if (args->env[i][j] != path[j] && path[j] != '\0')
				break;
			else if (args->env[i][j + 1] == '=' && path[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
