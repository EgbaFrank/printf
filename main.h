#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char_string_percent(char s, va_list args);
int print_int_specifiers(char s, va_list);


#endif /* MAIN_H */
