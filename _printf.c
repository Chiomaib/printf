
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
	int j = 0, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

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
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
			j++;
	}



	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of a buffer to stdout
 *
 * @buffer: The buffer containing the data to be printed
 *@buff_ind: Pointer to an integer representing the current index of the buffer
 *Description: This function prints the contents of a buffer to stdout,
 *              starting from the beginning of the buffer and continuing
 *              until the current index pointed to by buff_ind. It then
 *              resets the current index to 0.
 *
 *
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}


