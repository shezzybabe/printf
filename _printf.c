#include "main.h"

/**
 * print_buff - Prints the what is inside the buffer given it exists
 * @buffer: Array of characters
 * @buff_idx: Index that specifies where to add the next character
 */

void print_buff(char buffer[], int *buff_idx)
{
        if (*buff_idx > 0)
                write(1, &buffer[0], *buff_idx);

        *buff_idx = 0;
}

/**
 * _printf - Printf function replica
 * @format: format specifier
 *
 * Return: Printed characters
 */

int _printf(const char *format, ...)
{
	int i, printed_chars = 0, printed = 0;
	int size, flags, precision, width, buff_idx = 0;
	va_list ap;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_idx++] = format[i];
			if (buff_idx == BUFF_SIZE)
				print_buff(buffer, &buff_idx);

			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buff(buffer, &buff_idx);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ap, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);

			printed_chars += printed;
		}
	}

	print_buff(buffer, &buff_idx);

	va_end(ap);

	return (printed_chars);
}
