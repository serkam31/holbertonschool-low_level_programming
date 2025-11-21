#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct s_format - structure of format of input
 * @specifier: %d, %s, %c, %f
 * @func: pointer to function
 * Return: Always 0.
 */

typedef struct formats
{
	char *type;
	void (*func)(va_list);

} check;

void print_char(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void print_string(va_list args);
void print_all(const char *const format, ...);

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);

#endif
