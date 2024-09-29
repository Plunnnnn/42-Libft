#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <../libft/libft.h>

int		ft_printf(const char *format, ...);
int		handle_conversion(const char *conversion, va_list args);
char	*ft_utoa(unsigned int n);
int		handle_integer(int c);
int		handle_char(int c);
int		handle_string(char *str);
int		handle_base(unsigned long n, const char *base);
int		handle_unsigned(unsigned int value);

#endif