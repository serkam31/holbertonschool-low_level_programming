#include "main.h"

/**
 * rev_string - inverse une chaîne de caractères en mémoire
 * @s: pointeur vers la chaîne
 */
void rev_string(char *s)
{
	int i = 0;
	int start = 0;
	int end;
	char temp;


	while (s[i] != '\0')
		i++;

	end = i - 1;


	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
