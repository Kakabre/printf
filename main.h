#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int (*get_op(const char c))(va_list);
char *_strdup(char *str);
int _strlen_recursion(char *s);
int _puts(char *str);
char *convert_rot13(char *str);
int convert_alpha_numeric(int nb, int upper);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *convert_base_pointer(unsigned long p);
int print_unsigned(va_list ap);
int print_ptr(va_list ap);
int print_hexa_upper(va_list ap);
int print_hexa_lower(va_list ap);
int print_octal(va_list ap);
int print_nbr(va_list ap);
int print_binary(va_list ap);
int print_percent(va_list args__attribute__((unused)));
int print_rot13(va_list ap);
int print_str_reverse(va_list ap);
int print_str_unprintable(va_list ap);
int print_str(va_list ap);

#endif  /* _MAIN_H */
