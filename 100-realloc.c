#include "main.h"
#include <stdlib.h>

/**
 * _memcpy -> function that copies memory area.
 * @dest: pointer to the destination memory block
 * @src: pointer to the source memory block
 * @n: number of bytes from the memory area
 * Return: dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory block
 * @old_size: size of the old memory block
 * @new_size: size of the new memory block
 *
 * Return: pointer to the new memory block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *r;

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (ptr == NULL)
	{
		r = malloc(new_size);
		if (r == NULL)
		{
			return (NULL);
		}
		return (r);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	r = malloc(new_size);
	if (r == NULL)
	{
		return (NULL);
	}
	_memcpy(r, ptr, old_size);
	free(ptr);
	return (r);
}
