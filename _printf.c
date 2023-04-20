#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string.
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	int i, plus = 0;
	char *str;
	va_list folder;

	va_start(folder, format);

	for (i = 0 ; format && format[i] ; i++)
	{
	if (format[i] == '%')
	{
	i++;
	switch (format[1])
	{
	case 'c':
		plus += putchar((int)va_arg(folder, int));
		break;
	case 's':
		for (str = va_arg(folder, char *); *str; str++)
			putchar(*str);
		if (!str)
		str = NULL;
		plus += puts(str) - 1;
		break;
	case '%':
		plus += putchar('%');
		break;
	default:
	plus += putchar(format[i]) + putchar('%');
	break; }
	}
	else
	{
		plus += putchar(format[i]);
	}
	}
	va_end(folder);
	return (plus);
}
