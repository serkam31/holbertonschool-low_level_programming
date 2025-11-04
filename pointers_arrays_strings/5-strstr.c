#include "main.h"
#include<stdio.h>
/**
 * _strstr - locates a substring
 * @haystack: main string to search in
 * @needle: substring to find
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	// Si needle est vide, on renvoie haystack directement
	if (*needle == '\0')
		return (haystack);

	// Parcours du haystack
	for (i = 0; haystack[i] != '\0'; i++)
	{
		// Si les caractères correspondent
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		// Si on a atteint la fin du needle, c'est qu'on l'a trouvé
		if (needle[j] == '\0')
			return (&haystack[i]);
	}

	// Aucun match trouvé
	return (NULL);
}
