#include "shell.h"

/**
 *  * *strtow - Should split a string into words and ignore repeated delimiters
 *  * @str: Stands for the input string
 *  * @d: Stands for the delimeter string
 *  * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
int g, o, w, m, numwords = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (g = 0; str[g] != '\0'; g++)
if (!is_delim(str[g], d) && (is_delim(str[g + 1], d) || !str[g + 1]))
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, o = 0; o < numwords; o++)
{
while (is_delim(str[g], d))
g++;
w = 0;
while (!is_delim(str[g + w], d) && str[g + w])
w++;
s[o] = malloc((w + 1) * sizeof(char));
if (!s[o])
{
for (w = 0; w < o; w++)
free(s[w]);
free(s);
return (NULL);
}
for (m = 0; m < w; m++)
s[o][m] = str[g++];
s[o][m] = 0;
}
s[o] = NULL;
return (s);
}

/**
 *  * **strtow2 - Should split a string into words
 *  * @str: It is the input string
 *  * @d: It is the delimeter
 *  * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
int g, o, w, m, numwords = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
for (g = 0; str[g] != '\0'; g++)
if ((str[g] != d && str[g + 1] == d) ||
(str[g] != d && !str[g + 1]) || str[g + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (g = 0, o = 0; o < numwords; o++)
{
while (str[g] == d && str[g] != d)
g++;
w = 0;
while (str[g + w] != d && str[g + w] && str[g + w] != d)
w++;
s[o] = malloc((w + 1) * sizeof(char));
if (!s[o])
{
for (w = 0; w < o; w++)
free(s[w]);
free(s);
return (NULL);
}
for (m = 0; m < w; m++)
s[o][m] = str[g++];
s[o][m] = 0;
}
s[o] = NULL;
return (s);
}
