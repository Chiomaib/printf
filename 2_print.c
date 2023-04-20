#include <stdio.h>
#include <stdarg.h>
#include "main.h"
int _printf(const char *format, ...)
{
	va_list form;
	int sum = 0, i = 0;

	va_start(form, *format);
		while (*format)
	{
		if (*format == '%')
		{
		format++;
		if (*format == 'b')
		{

		unsigned int num = va_arg(form, unsigned int);
		char bin[32];

		while (num > 0)
		{
		bin[i++] = (num % 2) ? '1' : '0';
			sum >>= 1;
		}

		while (i > 0)
		{
		sum += putchar(bin[--i]);
		}
		}
		else
		{
		sum += putchar('%');
		if (*format)
		sum += putchar(*format++);
		}
		}
		else
		{
			sum += putchar(*format++);
		}
	}
		va_end(form);
		return (sum);
}
