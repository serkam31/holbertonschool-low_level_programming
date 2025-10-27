#include "main.h"
/**
 * more_numbers - prints 10 line of numbers from 0 to 14
 * Return: void
 */
void more_numbers(void)
{
	int ligne, n;

	for (ligne = 0; ligne < 10; ligne++)
	{
		for (n = 0; n <= 14; n++)
		{
			if (n > 10)
				_putchar((n / 10) + '0');
			_putchar((n % 10) + '0');
		}
		_putchar('\n');
	}
}
