#include "main.h"

/**
 * print_char_string_percent - handles c, s and % specifiers
 * @s: conversion specifier
 * @args: list of with arguments
 *
 * Return: no. of characters printed
 */

int print_char_string_percent(char s, va_list args)
{
	int chars_printed = 0;
	char *str;

	if (!s)
		return (-1);
	switch (s)
	{
		case 'c':
			putchar(va_arg(args, int));
			chars_printed++;
			break;
		case 's':
			chars_printed += printf("%s", va_arg(args, char *));
			break;
		case '%':
			putchar('%');
			chars_printed++;
			break;
		case 'S':
			str = va_arg(args, char *);

			while (*str)
			{
				if (*str >= 0 && *str < 32 || *str >= 127)
						chars_printed += printf("\\x%02X", (unsigned char)(*str));
				else
				{
					putchar(*str);
					chars_printed++;
				}
				str++;
			}
			break;
	}
	return (chars_printed);
}

/**
 * print_int_specifiers - handles int specifiers
 * @s: conversion specifier
 * @args: list with arguments
 *
 * Return: no. of characters printed
 */

int print_int_specifiers(char s, va_list args)
{
	int chars_printed = 0, bits[32], bit_count = 0, i;
	unsigned int n;

	switch (s)
	{
		case 'd':
		case 'i':
			chars_printed += printf("%d", va_arg(args, int));
			break;
		case 'b':
			n = va_arg(args, unsigned int);
			for (i = 31; i >= 0; i--)
			{
				bits[i] = n % 2;
				n /= 2;
				bit_count++;
			}

			for (i = 32 - bit_count; i < 32; i++)
				putchar(bits[i] + '0');

			chars_printed += bit_count;
			break;
		case 'p':
			chars_printed += printf("%p", va_arg(args, void *));
			break;

	}
	return (chars_printed);
}

/**
 * print_unsigned_octal_hex - handles the u, o, x and X specifiers
 * @s: conversion specifier
 * @args: list with arguments
 *
 * Return: no. of characters printed
 */

int print_unsigned_octal_hex(char s, va_list args)
{
	int chars_printed = 0;

	switch (s)
	{
		case 'u':
			chars_printed += printf("%u", va_arg(args, unsigned int));
			break;
		case 'o':
			chars_printed += printf("%o", va_arg(args, unsigned int));
			break;
		case 'x':
			chars_printed += printf("%x", va_arg(args, unsigned int));
			break;
		case 'X':
			chars_printed += printf("%X", va_arg(args, unsigned int));
			break;
	}
	return (chars_printed);
}
