#include "shell.h"

/**
 * free_globe - a function that frees buffers
 * @pt: pointer to be freed
 * Return: void
 */

void free_globe(char **pt)
{
	unsigned int k = 0;

	if (!pt || pt == NULL)
		return;
	while (pt[k])
	{
		free(pt[k]);
		k++;
	}
	free(pt);
}
