#ifndef MAIN
#define MAIN
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define S_LONG 2
#define S_SHORT 1

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */

typedef struct fmt fmt_t;

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

int _printf(const char *format, ...);
int print_arg(const char *fmt, int *i,
va_list list, char buffer[], int flag, int width, int precision, int size);

int _print_int(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int _print_binary(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int _print_unsigned(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int _print_octal(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int _print_hexadecimal(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int _print_hexa_upper(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int _print_hexa(va_list type, char map_to[],
	char buffer[], int flag, char flag_ch, int width, int precision, int size);

int _print_char(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int _print_string(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int _print_percent(va_list type, char buffer[],
	int flag, int width, int precision, int size);

int _print_non_printable(va_list type, char buffer[],
	int flag, int width, int precision, int size);

int print_pointer(va_list type, char buffer[],
	int flag, int width, int precision, int size);

int _flag(const char *format, int *i);
int _width(const char *format, int *i, va_list ap);
int _size(const char *format, int *i);
int _precision(const char *format, int *i, va_list ap);

int _is_printable(char);
int _append_hexa_code(char, char[], int);
int _is_digit(char);

long int _convert_size_number(long int num, int size);
long int _convert_size_unsgnd(unsigned long int num, int size);

int print_reverse(va_list type, char buffer[],
	int flag, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list type, char buffer[],
	int flag, int width, int precision, int size);

/* width handler */
int _handle_write_char(char c, char buffer[],
	int flag, int width, int precision, int size);
int _write_number(int is_positive, int idx, char buffer[],
	int flag, int width, int precision, int size);
int _write_num(int idz, char bff[], int flag, int width, int precision,
	int length, char padd, char extra_c);
int _write_pointer(char buffer[], int idz, int length,
	int width, int flag, char padd, char extra_c, int padd_start);
int _write_unsgnd(int is_negative, int idx,
		char buffer[],int flag, int width, int precision, int size)
#endif
