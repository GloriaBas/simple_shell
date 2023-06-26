#include "shell.h"

/**
 * _strncpy - A function that copies a string
 * @src: parameter
 * @dest: parameter
 * @n: parameter
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strcmp - A function that compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: positive, negative or zero
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strlen -  A function to get the length of a string
 * @str: string to be measured
 * Return: the length of a string
 */

int _strlen(char *str)
{
	int len = 0;

	while (*(str + len))
	{
		len++;
	}
	return (len);
}