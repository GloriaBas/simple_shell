#include "shell.h"

/**
 * *_eputs - Should print an input string
 * * @str: Represents the string to be printed
 * *Return: ()
 */
void _eputs(char *str)
{
int g = 0;
if (!str)
return;
while (str[g] != '\0')
{
_eputchar(str[g]);
g++;
}
}

/**
 * * _eputchar - Should write the char to stderr
 * * @c: Stands for the char to be printed
 * * Return: On success 1.
 * * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
static int g;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || g >= WRITE_BUF_SIZE)
{
write(2, buf, g);
g = 0;
}
if (c != BUF_FLUSH)
buf[g++] = c;
return (1);
}

/**
 * * _putfd - Should write the char to the given fd
 * * @c: Stands for the char to be printed
 * * @fd: Stands for the filedescriptor to be written to
 * * Return: On success 1.
 * * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
static int g;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || g >= WRITE_BUF_SIZE)
{
write(fd, buf, g);
g = 0;
}
if (c != BUF_FLUSH)
buf[g++] = c;
return (1);
}

/**
 * *_putsfd - Should print an input string.
 * * @str: Represents the string to be printed.
 * * @fd: Is the filedescriptor to write to
 * * Return: The number of chars put
 */
int _putsfd(char *str, int fd)
{
int g = 0;
if (!str)
return (0);
while (*str)
{
g++ = _putfd(*str++, fd);
}
return (g);
}
