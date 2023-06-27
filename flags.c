#include "main.h"

/**
 * _flags - determines active flags
 * @format: Formatted string in which to print the arguments
 * @i: ...
 *
 * Return: Flags:
 */

int _flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, k;
	int flags = 0;
	const char flag_chars[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_arrays[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; flag_chars[j] != '\0'; j++)
			if (format[k] == flag_chars[j])
			{
				flags |= flag_arrays[j];
				break;
			}

		if (flag_chars[j] == 0)
			break;
	}

	*i = k - 1;

	return (flags);
}
