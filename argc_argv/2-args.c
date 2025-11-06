#include <stdio.h>
/**
 * main - prints all arguments passed to the program
 * @argc: number of arguments
 * @argv: array pf arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
