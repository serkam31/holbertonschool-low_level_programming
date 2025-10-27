#include "main.h"
/**
 * print_diagonal - draws a diagonal
 * @n: number of times \ should be printed
 * Return: void
 */
void print_diagonal(int n)
{
	int l, e;

	for (l = 0; l < n; l++)
	{
		for (e = 0; e < l; e++)
			_putchar(' ');

		_putchar('\\');
		_putchar('\n');
	}
	if (n <= 0)
		_putchar('\n');
}
