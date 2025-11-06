#include <stdio.h>
#include <stdlib.h>
/**
 * main - multiple two numbers from command-line arguments
 * @argc: number of arguments
 * @argv: array of arguments strings
 * Return: 0 on success, 1 if number of arguments is incorect
 */
int main(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d\n", a * b);
	return (0);
}
