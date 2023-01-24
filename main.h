#ifindef _PRINTF_H
m_to - prints a range of char addresses
 * @start: starting address
 *  * @stop: stopping address
 *   * @except: except address
 *    *
 *     * Return: number bytes printed
 *      */
 int print_from_to(char *start, char *stop, char *except)
{
		int sum = 0;

			while (start <= stop)
					{
								if (start != except)
												sum += _putchar(*start);
										start++;
											}
				return (sum);
}

/**
 *  * print_rev - prints string in reverse
 *   * @ap: string
 *    * @params: the parameters struct
 *     *
 *      * Return: number bytes printed
 *       */
int print_rev(va_list ap, params_t *params)
{
		int len, sum = 0;
			char *str = va_arg(ap, char *);
				(void)params;

					if (str)
							{
										for (len = 0; *str; str++)
														len++;
												str--;
														for (; len > 0; len--, str--)
																		sum += _putchar(*str);
															}
						return (sum);
}

/**
 *  * print_rot13 - prints string in rot13
 *   * @ap: string
 *    * @params: the parameters struct
 *     *
 *      * Return: number bytes printed
 *       */
int print_rot13(va_list ap, params_t *params)
{
		int i, index;
			int count = 0;
				char arr[] =
							"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
					char *a = va_arg(ap, char *);
						(void)params;

							i = 0;
								index = 0;
									while (a[i])
											{
														if ((a[i] >= 'A' && a[i] <= 'Z')
																		    || (a[i] >= 'a' && a[i] <= 'z'))
																	{
																					index = a[i] - 65;
																								count += _putchar(arr[index]);
																										}
																else
																				count += _putchar(a[i]);
																		i++;
																			}
										return (count);
}
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* convert_number.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, params_t *params, va_list ap);

/* _prinf.c module */
int _printf(const char *format, ...);

