#include"main.h"
/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search in
 * @accept: string containing the characters to match
 *
 * Return: pointer to the first occurrence in s of any of the bytes in accept,
 *         or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (&s[i]);
		}

	}
	return (0);
}
