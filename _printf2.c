#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string passed as a format.
 *
 * Return: no. of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0;

	va_start(args, format);

	if (!format) /* if format is null */
		return (-1);

	while (*format)
	{
		if (*format == '%' && format++)
		{
			if (*format == 'c' || *format == 's' || *format == '%' || *format == 'S')
				chars_printed += print_char_string_percent(*format, args);
			else if (*format == 'd' || *format == 'i' || *format == 'b' || *format == 'p')
				chars_printed += print_int_specifiers(*format, args);
			else
				chars_printed += print_unsigned_octal_hex(*format, args);
		}
		else
		{
			putchar(*format); /* print regular characters */
			chars_printed++;
		}
		format++;
	}
	va_end(args);
	return (chars_printed);
}
