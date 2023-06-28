#include "shell.h"

/**
 * globe_memset - A function that fills memory with a constant byte.
 * @s: pointer to the memory area
 * @b: the value(byte) to copy
 * @n: size of value
 * Return: pointer to the memory area
 */

char *globe_memset(char *s, char b, unsigned int n)
{
	unsigned int g;

	for (g = 0; g < n; g++)
	{
		*(s + g) = b;
	}
	return (s);
}

/**
 * free_globe - frees buffers
 * @pt: pointer to be freed
 * Return: void
 */

void free_globe(char **pt)
{
	unsigned int g = 0;

	if (!pt || pt == NULL)
	return;

	while (pt[g])
	{
		free(pt[g]);
		g++;
	}
	free(pt);
}


/**
 * globe_realloc - Reallocates a memory block using malloc and free
 * @ptr: previous pointer to the memory
 * @new_size: size of new pointer
 * @old_size: size of previous pointer
 * Return: pointer to new allocated space
 */

void *globe_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr; *char _ptr;
	unsigned int g;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	char_ptr = ptr;

	new_ptr = malloc(sizeof(char) * new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		for (g = 0; g < old_size; g++)
			new_ptr[g] = char_ptr[g];
	}
	free(ptr);
	return (new_ptr);
}


