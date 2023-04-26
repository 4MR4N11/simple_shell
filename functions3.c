
#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest
 * @dest: Pointer to the destination array where the content is to be copied
 * @src: Pointer to the source of data to be copied
 * @n: Number of bytes to be copied
 * Return: Pointer to the destination array
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
 * @ptr: pointer to the memory previously allocated.
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
