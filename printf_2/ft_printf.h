#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *str, ...);
int ft_putchar(char c, int ret);
int ft_putnbr(long x, int ret);
int ft_putstr(char *str, int ret);
int ft_puthex_ll(unsigned long long p, int ret);
int ft_puthex_ui(unsigned int p, int k, int ret);
int printer( char *str, va_list args);
int spec_check(va_list args, char c, int ret);
#endif