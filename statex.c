#include "shell.h"

/**
 * *_strncpy - Should copy a string
 * *@dest: It is the destination string to be copied to
 * *@src: It is the source string
 * *@n: It is the amount of characters to be copied
 * *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
int g, o;
char *s = dest;
g = 0;
while (src[g] != '\0' && g < n - 1)
{
dest[g] = src[g];
g++;
}
if (g < n)
{
o = g;
while (o < n)
{
dest[o] = '\0';
o++;
}
}
return (s);
}

/**
 * *_strncat - Should concatenate two strings
 * *@dest: It is the first string
 * *@src: It is the second string
 * *@n: It is the amount of bytes to be maximally used
 * *Return: It is the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
int g, o;
char *s = dest;
g = 0;
o = 0;
while (dest[g] != '\0')
g++;
while (src[o] != '\0' && o < n)
{
dest[g] = src[o];
g++;
o++;
}
if (o < n)
dest[g] = '\0';
return (s);
}

/**
 * *_strchr - Should locate a char in a string
 * *@s: It is the string to be parsed
 * *@c: It is the character to look for
 * *Return: (s) a pointer to the memory area
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}
