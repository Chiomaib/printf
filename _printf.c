
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Produces output according to a format
 *
 * @format: Pointer to a format string
 * Return: Number of characters written
 */
int _printf(const char *format, ...)
{
	int j= 0, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list form;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(form, format);

	while (format && format[j] != '\0')
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, form);
			precision = get_precision(format, &j, form);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, form, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
		j++;
	}

	print_buffer(buffer, &buff_ind);

	va_end(form);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * bug: Array of chars
 * @bug: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *bug)
{
	if (*bug > 0)
		write(1, &buffer[0], *bug);

	*bug = 0;
}

