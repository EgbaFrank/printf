#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: no. of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0;
	const char *ptr = format;
	char *str;

	if (format == NULL)
		return(-1);

	va_start(args, format);
	while (*ptr) /* iterate the entire string excludig null */
	{
		if (*ptr == '%' && ptr != NULL) /* if there is a format specifier */
		{
			ptr++; /* move to the next character*/

			if (*ptr == 'c')
			{
				putchar(va_arg(args, int)); /* int cause its stored in ASCII*/
				chars_printed++;
			}
			else if (*ptr == 's')
			{
				str = va_arg(args, char *);
				while (*str)
				{
					putchar(*str);
					chars_printed++;
					str++;
				}
			}
			else if (*ptr == '%')
			{
				putchar('%');
				chars_printed++;
			}
			else if (*ptr == 'd' || *ptr == 'i')
			{
				chars_printed += printf("%d",(va_arg(args, int)));
			}
			else if (*ptr == 'b')
			{
				chars_printed += printf("%b", (va_arg(args, unsigned int)));
			}
		}
		else
		{
			putchar(*ptr);
			chars_printed++;
		}
		ptr++;
	}
	va_end(args);
	return (chars_printed); /* no of chars printed */
}
