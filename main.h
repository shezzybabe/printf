#ifndef MAIN
#define MAIN

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* all the flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* all the sizes */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: format
 * @fn: The corresponding function
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: format.
 * @fm_t: The corresponding function
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int _handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */

int _print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */

int _print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int _print_hexa(va_list types, char map_to[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */

int _print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print the memory address */

int _print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions concerned with other specifiers */

int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list list);
int _precision(const char *format, int *i, va_list list);
int _size(const char *format, int *i);

/*Function to print string in reverse*/

int _print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13 format*/

int _print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width */

int _handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);

int _write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);

int _write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);

int _write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int _write_unsgnd(int is_negative, int ind,
	char buffer[], int flags, int width, int precision, int size);

/*other functions*/
int _is_printable(char);
int _append_hexa_code(char, char[], int);
int _is_digit(char);

long int _convert_size_number(long int num, int size);
long int _convert_size_unsgnd(unsigned long int num, int size);

#endif

