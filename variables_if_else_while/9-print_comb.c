#include<stdio.h>
/**
 * main - Prints all single digit numbers of base 10 separated by comma and space
 * Return: Always 0 (Success)
 */
int main(void)
{
	int numbers = 0;

	while (numbers <= 9)
	{
		putchar(numbers + '0');

		if  (numbers < 9)
		{
			putchar(',');
			putchar(' ');
		}

		numbers++;
	}
	putchar('\n');

	return (0);
}
