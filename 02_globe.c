#include "shell.h"

/**
 * * _erratoi - Should convert a string to an integer.
 * * @s: Stands for the string to be converted.
 * * Return: 0 if no numbers in string, converted number otherwise
 * * -1 on error
 */
int _erratoi(char *s)
{
int g = 0;
unsigned long int result = 0;
if (*s == '+')
s++;  /* TODO: how does this make main return 255? */
for (g = 0;  s[g] != '\0'; g++)
{
if (s[g] >= '0' && s[g] <= '9')
{
result *= 10;
result += (s[g] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
 * * print_error - Should print an error message
 * * @info: Represents the parameter & return info struct
 * * @estr: It is the string containing specified error type
 * * Return: 0 if no numbers in string, converted number otherwise
 * *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * * print_d - Should be the function that prints
 * * a decimal (integer) number (base 10)
 * * @input: Stands for the input
 * * @fd: It is the filedescriptor to write to
 * * Return: number of characters printed.
 */
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int g, count = 0;
unsigned int _abs_, current;
if (fd == STDERR_FILENO)
_putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
_putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (g = 1000000000; g > 1; g /= 10)
{
if (_abs_ / g)
{
_putchar('0' + current / g);
count++;
}
current %= g;
_putchar('0' + current);
count++;
return (count);
}

/**
 * * convert_number - It is the converter function, a clone of itoa
 * * @num: Stands for number
 * * @base: Stands forbase
 * * @flags: Stands forargument flags
 * * Return: Stands for string
 */
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * * remove_comments - Shpould be a function that
 * * replaces first instance of '#' with '\0'
 * * @buf: It is the address of the string to modify
 * * Return: Always 0;
 */
void remove_comments(char *buf)
{
int g;
for (g = 0; buf[g] != '\0'; g++)
if (buf[g] == '#' && (!g || buf[g - 1] == ' '))
{
buf[r] = '\0';
break;
}
}
