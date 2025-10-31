#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s: pointer to the string
 * Return: the integer represented by the string
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	while (s[i] != '\0' && !(s[i] >= '0' && s[i] <= '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		if (sign == -1)
			result = result * 10 - (s[i] - '0');
		else
			result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}
