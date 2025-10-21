#include<stdio.h>
/**
 * main - Prints all single digit numbers of base 10
 * Return: Always 0 (Success)
 */
int main(void)
{
	int numbers = 0;

	while (numbers <= 9)
	{
		putchar(numbers + '0');
		numbers++;
	}
	putchar('\n');

	return (0);
}
