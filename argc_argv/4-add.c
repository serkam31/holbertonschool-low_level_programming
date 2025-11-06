#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - checks if a string represents a positive number
 * @s: the string to check
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_number(char *s)
{
	int i = 0;

	if (s[0] == '\0')
		return (0);

	while (s[i])
	{
		if (!isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - adds positive numbers passed as command line arguments
 * @argc: number of arguments
 * @argv: array of arguments strings
 *
 * Return: 0 success, 1 if an argument is not a number
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
