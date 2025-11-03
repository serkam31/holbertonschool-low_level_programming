#include "main.h"
/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: characters to accept
 *
 * Return: number of characters in initial segment of s
 *         consisting only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0, j;
	int found;

	while (s[i])
	{
		found = 0;
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		i++;
	}
	return (i);
}
