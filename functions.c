#include "main.h"

int divider_len(int n)
{
	int i;

	i = 1;
	while((n / 10) != 0)
	{
		n /= 10;
		i *= 10;
	}
	return (i);
}

void print_number(int n)
{
	int tmp, l;
	char c;

	l = divider_len(n);
	tmp = l;
	while (l != 0)
	{
		if (n < 0)
		{
			if (tmp == 1)
				write (1, "-", 1);
			c = (((n / 1) * -1) + '0');
			write(1, &c, 1);
		}
		else
		{
			c = ((n / 1) + '0');
			write(1, &c, 1);
		}
		n %= 1;
		l /= 10;
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
        {
                dest[len + i] = src[i];
        }
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
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
        int len = 0;
        int i = 0;

        while (src[len] != '\0')
        {
                len++;
        }
        while (i < (len + 1))
        {
                dest[i] = src[i];
                i++;
        }
        return (dest);
}
