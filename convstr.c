#include "shell.h"
/**
 * * interactive - Should return true when shell is in interactive mode
 * * @info: Represents the struct address
 * *
 * * Return: 1 if in interactive mode, 0 if otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * * is_delim - Should check if character is a delimeter
 * * @c: It is the char to check
 * * @delim: It is the delimeter string
 * * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 * *_isalpha - Should check for alphabetic character(s)
 * *@c: The character to input
 * *Return: 1 when c is alphabetic, 0 when otherwise
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * *_atoi - Should convert a string to an integer
 * *@s: Represents the string to be converted
 * *Return: 0 when there is no number in string,
 * *converted number when otherwise
 */

int _atoi(char *s)
{
int g, sign = 1, flag = 0, output;
unsigned int result = 0;
for (g = 0;  s[g] != '\0' && flag != 2; g++)
{
if (s[g] == '-')
sign *= -1;
if (s[g] >= '0' && s[g] <= '9')
{
flag = 1;
result *= 10;
result += (s[g] - '0');
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}
