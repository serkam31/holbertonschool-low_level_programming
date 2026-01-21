#include"main.h"
#include <stdio.h>
/**
 * _strchr - function that locate a character
 * @s: pointer to the string to search
 * @c: character to find
 *
 * Return: pointer to the character c
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (c == '\0')
		return (s);

	return (NULL);
}
