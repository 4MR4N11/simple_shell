#include "main.h"

/**
 * print_number -> function that prints an integer
 * @num: integer to print
*/
void print_number(int num)
{
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num == 0)
		write(1, "0", 1);
	else
	{
		char num_str[12];
		int i = 0;

		while (num != 0)
		{
			num_str[i] = (num % 10) + '0';
			num /= 10;
			i++;
		}
		num_str[i] = '\0';
		for (i = i - 1; i >= 0; i--)
			write(1, &num_str[i], 1);
	}
}
/**
 * _strcat -> function that concatenates two strings
 * @dest: pointer to string
 * @src: pointer to string
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int i;

	while (dest[len] != '\0')
	{
		len++;
	}
	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strlen -> function that returns the length of a string.
 * @s: pointer to a string
 * Return: length of a string
 */
int _strlen(char *s)
{
	int len = 0;
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * _strcpy - function that copies the string pointed to by src
 * @src: pointer to string
 * @dest: pointer to string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0;
	int i = 0;

	while (src[len] != '\0')
		len++;
	while (i < (len + 1))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
