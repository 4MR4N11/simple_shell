
#include "main.h"

/**
 * _memcpy - copy n number of bytes from src to dest.
 * @dest: pointer to the destination.
 * @src: pointer to the source.
 * @n: number of bytes to copy.
 * Return: @dest.
 */

void *_memcpy(void *dest, const void *src, int n)
{
	int i;
	char *dest2;
	char *src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

/**
 * _realloc - reallocates a memory block using malloc and free.
 * The contents will be copied to the newly allocated space.
 * @ptr: pointer to the memory previously allocated with a call to malloc.
 * @old_size: the size, in bytes, of the allocated space for ptr.
 * @new_size: the new size, in bytes of the new memory block.
 * Return: new pointer to the new created memory area.
 * NULL if it fails.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if ((new_size == 0) && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (new_size > old_size)
		_memcpy(new_ptr, ptr, old_size);
	else
		_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

char *_strpbrk(const char *str1, const char *str2)
{
	const char *ptr1 = str1;

	while (*ptr1 != '\0')
	{
		const char *ptr2 = str2;

		while (*ptr2 != '\0')
		{
			if (*ptr1 != *ptr2)
			{
				return ((char *)ptr1);
			}
			ptr2++;
		}
		ptr1++;
	}
	return (NULL);
}

size_t _strspn(const char *str1, const char *str2)
{
	size_t count = 0;
	const char *ptr1 = str1;

	while (*ptr1 != '\0')
	{
		const char *ptr2 = str2;

		while (*ptr2 != '\0')
		{
			if (*ptr1 == *ptr2)
			{
				count++;
				break;
			}
			ptr2++;
		}
		if (*ptr2 == '\0')
		{
			return (count);
		}
		ptr1++;
	}
	return (count);
}

char *_strtok(char *str, const char *delim)
{
	static char *last;
	char *token = NULL;

	if (str != NULL)
	{
		last = str;
	}
	else
	{
		if (last == NULL)
		{
			return (NULL);
		}
		str = last;
	}
	str += _strspn(str, delim);
	if (*str == '\0')
	{
		last = NULL;
		return (NULL);
	}
	token = str;
	str = _strpbrk(token, delim);
	if (str == NULL)
	{
		last = NULL;
	}
	else
	{
		*str = '\0';
		last = str + 1;
	}
	return (token);
}
