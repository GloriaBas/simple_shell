#include "shell.h"

/**
 * *_eputs - Should print an input string
 * * @str: Represents the string to be printed
 * *Return: ()
 */
void _eputs(char *str)
{
int y = 0;
if (!str)
return;
while (str[y] != '\0')
{
_eputchar(str[y]);
y++;
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
static int y;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
{
write(2, buf, y);
y = 0;
}
if (c != BUF_FLUSH)
buf[y++] = c;
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
static int y;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, y);
y = 0;
}
if (c != BUF_FLUSH)
buf[y++] = c;
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
int y = 0;
if (!str)
return (0);
while (*str)
{
y++ = _putfd(*str++, fd);
}
return (y);
}
