#include "shell.h"

/**
 * _puts - A function that prints a string, followed by new line, to stdout.
 * @str: parameter
 * Return: nothing
 */

void _puts(char *str)
{
	int g;

	for (g = 0; str[g] != '\0'; g++)
	{
		_putchar(str[g]);
	}
	_putchar('\n');
}

/**
 * _strdup - A function that returns a pointer to newly allocated memory
 * space, that contains a copy of the string
 * @str: string parameter
 * Return: Always 0
 */

char *_strdup(char *str)
{
	char *copy;

	if (str == NULL)
	{
		return (NULL);
	}

	copy = (char *)malloc(strlen(str) + 1);

	if (copy == NULL)
	{
		return (NULL);
	}

	strcpy(copy, str);
	return (copy);
}

/**
 * _putchar - A functions that writes the character c to stdout
 * @c: the character to print
 * Return: On success 1, -1 on error,and errno is set appropriately.
 */

int _putchar(char c)
{
	static int g;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || g >= WRITE_BUF_SIZE)
	{
		write(1, buf, g);
		g = 0;
	}
	if (c != BUF_FLUSH)
		buf[g++] = c;
	return (1);
}
