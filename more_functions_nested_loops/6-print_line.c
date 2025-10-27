#include "main.h"
/**
 * print_line - prints a draw line
 * @n: number of _
 * Return: void
 */
void print_line(int n)
{
	int espace = 0;

	while (espace < n)
	{
		_putchar('_');
		espace++;
	}
	_putchar('\n');
}
