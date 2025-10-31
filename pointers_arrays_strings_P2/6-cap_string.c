#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to str
 */
char *cap_string(char *str)
{
	int i = 0;
	int j;
	int cap_next = 1;
	char separators[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		if (cap_next && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 'a' - 'A';
		}

		cap_next = 0;
		j = 0;
		while (separators[j] != '\0')
		{
			if (str[i] == separators[j])
			{
				cap_next = 1;
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}
