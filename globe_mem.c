#include "shell.h"

/**
 * * bfree - Should free a pointer and make the address NULL
 * * @ptr: It is the address of the pointer to free
 * * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
