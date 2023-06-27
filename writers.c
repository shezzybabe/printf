#include "main.h"

/**
 * _write_number - Prints a string
 * @is_negative: Lista of arguments
 * @idx: char type.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int _write_number(int is_negative, int idx, char buffer[],
	int flag, int width, int precision, int size)
{
	int length = BUFF_SIZE - idx - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flag & F_PLUS)
		extra_ch = '+';
	else if (flag & F_SPACE)
		extra_ch = ' ';

	return (write_num(idx, buffer, flag, width, precision,
		length, padd, extra_ch));
}

/**
 * _handle_write_char - Prints a string
 * @c: char type.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flag.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int _handle_write_char(char c, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * _write_num - Write a number using a bufffer
 * @idx: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */

int _write_num(int idx, char buffer[], int flag, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
		buffer[idx] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--idx] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--idx] = extra_c;
			return (write(1, &buffer[idx], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--idx] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[idx], length));
		}
		else if (!(flag & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[idx], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--idx] = extra_c;
	return (write(1, &buffer[idx], length));
}

/**
 * _write_unsgnd - Writes an unsigned number
 * @is_negative: Number idxicating if the num is negative
 * @idx: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flag: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */

int _write_unsgnd(int is_negative, int idx,
	char buffer[],
	int flag, int width, int precision, int size)
{
	int length = BUFF_SIZE - idx - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && idx == BUFF_SIZE - 2 && buffer[idx] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--idx] = '0';
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flag & F_MINUS)
		{
			return (write(1, &buffer[idx], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[idx], length));
		}
	}

	return (write(1, &buffer[idx], length));
}

/**
 * _write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @idx: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flag: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */

int _write_pointer(char buffer[], int idx, int length,
	int width, int flag, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--idx] = 'x';
			buffer[--idx] = '0';
			if (extra_c)
				buffer[--idx] = extra_c;
			return (write(1, &buffer[idx], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--idx] = 'x';
			buffer[--idx] = '0';
			if (extra_c)
				buffer[--idx] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[idx], length));
		}
		else if (!(flag & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[idx], length - (1 - padd_start) - 2));
		}
	}
	buffer[--idx] = 'x';
	buffer[--idx] = '0';
	if (extra_c)
		buffer[--idx] = extra_c;
	return (write(1, &buffer[idx], BUFF_SIZE - idx - 1));
}
