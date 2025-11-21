#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "variadic_functions.h"

/**
 * print_char - Write a function that prints char
 * @args: type argument
 * Return: void
 */

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - Write a function that prints int
 * @args: type argument
 * Return: void
 */

void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - Write a function that prints float
 * @args: type argument
 * Return: void
 */

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - Write a function that prints string
 * @args: type argument
 * Return: void
 */

void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - Write a function that prints all
 * @format: type argument
 * Return: void
 */

void print_all(const char *const format, ...)
{
	int i = 0;
	int cifs = 0;
	char *separator = "";
	va_list args;

	check str[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}};

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		while (cifs < 4)
		{
			if (format[i] == *str[cifs].type)
			{
				printf("%s", separator);
				str[cifs].func(args);
				separator = ", ";
			}
			cifs++;
		}
		i++;
		cifs = 0;
	}
	printf("\n");
	va_end(args);
}
