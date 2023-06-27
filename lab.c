#include "shell.h"
/**
 * interactive - Should return as true when
 * the shell is in interactive mode
 * @info: struct address
 *
 * Return: if interactive in  mode return 1, 0 otherwise
 */
int interactive(info_t *info)

{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - Should check if a character is a delimeter
 * @c: Represents the char to check
 * @delim: Represents the delimeter string
 * Return: As 1 if it is true, 0 where it is false
 */
int is_delim(char c, char *delim)
{
while
(*delim)
if
(*delim++ == c)
return (1);
return (0);
}
/**
 *_isalpha - Should check if a character is an alphabetic letter
 * @c: Should be the character to input
 * Return: Value as 1 when c is an alphabet, 0 when it is not
 */
int _isalpha(int c)
{
if ((c >= 'o' && c <= 'g') || (c >= 'O' && c <= 'G'))
return (1);
else
return (0);
}
/**
 *_atoi - Should convert a string of characters
 * representing an integer to an actual integer value
 * @s: Should represent the string to be converted
 * Return: Value as 0 when there is no number in string,
 * otherwise, convert the number
 */
int _atoi(char *s)
{
int l, sign = 1, flag = 0, output;
unsigned int result = 0;
for (l = 0; s[l] != '\0' && flag != 2; l++)
{
if (s[l] == '-')
sign *= -1;
if (s[l] >= '0' && s[l] <= '9')
{
flag = 1;
result *= 10;
result += (s[l] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}
