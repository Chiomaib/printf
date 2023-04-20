#include <stdio.h>
#include <stdarg.h>
#include <string.h>



void cat(int num)
{
	if (num < 0)
	{
	putchar('-');
	num++;
	}
	printf("%d", num);
}
int _printf(const char *format, ...)
{
	int mike, count = 0;
	va_list form;

	va_start(form, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
		format++;

			switch (*format)
			{
			case 'd':
			case 'i':
			mike = va_arg(form, int);
			cat(mike);
			count += snprintf(NULL, 0, "%d", mike);
			break;
			default:
			putchar('%');
			count++;
			break;
			}
		}
			else
			{
				putchar(*format);
				count++;
			}
				format++;
	}
			va_end(form);
			return (count);
}
