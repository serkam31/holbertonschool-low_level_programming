#include "main.h"

/**
 * string_toupper - converts lowercase letters to uppercase
 * @str: string to modify
 *
 * Return: pointer to str
 */
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 'a' - 'A';
		}

		i++;
	}

	return (str);
}
