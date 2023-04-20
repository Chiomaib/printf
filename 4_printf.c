#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list form;

	va_start(form, *format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
		format++;
		switch (*format)
		{
			case 'u':
		printf("%u", va_arg(form, unsigned int));
			break;
			case 'o':
		printf("%o", va_arg(form, unsigned int));
			break;
			case 'x':
		printf("%x", va_arg(form, unsigned int));
			break;
			case 'X':
		printf("%X", va_arg(form, unsigned int));
			break;
			default:
			printf("invalid declaration specifier");
		}
		}
		else
		{
			printf("%c", *format);
		}
		format++;
	}
		va_end(form);
		return (*format);
}
