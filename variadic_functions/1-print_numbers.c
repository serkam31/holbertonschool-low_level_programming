#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - prints numbers separated by a string
 * @separator: string printed between numbers (or NULL for no separator)
 * @n: number of integers passed to the function
 *
 * Return: nothing (void)
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 1; i <= n; i++)
	{
		printf("%d", va_arg(args, int));
		if (i < n && separator != NULL)
			printf("%s", separator);
	}
	va_end(args);
	printf("\n");
}
