#include "main.h"

/**
 * _print_char - Prints a character
 * @type: List of the arguments
 * @buffer: a buffer array that is used to handle print
 * @flag: determines active flags
 * @precision: Precision
 * @width: widdth
 * @size: Size
 * Return: Number of chars printed
 */

int _print_char(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	char c = va_arg(type, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * _print_string - Prints a string
 * @type: List of the arguments
 * @buffer: Buffer array that handles printing
 * @flag:  determines active flags
 * @width: gets width.
 * @precision: Precision specifier
 * @size: Size specification
 * Return: printed characters count
 */

int _print_string(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(type, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size)
		;
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * _print_int - Print int
 * @type: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flag: active flags
 * @width: width.
 * @precision: Precision
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */

int _print_int(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(type, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flag, width, precision, size));
}

/**
 * _print_binary - Prints an unsigned integer
 * @type: Lists of the arguments
 * @buffer: Buffer that handles print
 * @flag:  Calculate active flags
 * @width: width.
 * @precision: Precision specifier
 * @size: Size
 *
 * Return: Numbers of char printed
 */
int _print_binary(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	unsigned int i, j, k, sum;
	unsigned int a[32];
	int count;

	UNUSED(precision);
        UNUSED(size);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);

	j = va_arg(types, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	a[0] = j / k;

	for (i = 1; i < 32; i++)
	{
		k /= 2;
		a[i] = (j / k) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * _print_percent - Prints a percent sign
 * @type: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int _print_percent(va_list type, char buffer[],
        int flag, int width, int precision, int size)
{
	UNUSED(size);
	UNUSED(type);
	UNUSED(buffer);
        UNUSED(flag);
	UNUSED(precision);
        UNUSED(width);
        return (write(1, "%%", 1));
}
