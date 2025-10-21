#include<stdio.h>
/**
 * main - Prints all single digit numbers of base 10
 * Return: Always 0 (Success)
 */
int main(void)
{
	int numbers = 0;
	char hexa = 'a';

	while (numbers <= 9)
	{
		putchar(numbers + '0');
		numbers++;
	}

	while (hexa <= 'f')
	{
		putchar(hexa);
		hexa++;
	}

	putchar('\n');

	return (0);
}
