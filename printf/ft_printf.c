#include "ft_printf.h"

int spec_check(va_list args, char c, int ret)
{
    unsigned int u;
    unsigned long long p;

    u = 0;
    p = 0;
    if (c == 'c')
        ret = ft_putchar(va_arg(args, int), ret);
    else if (c == 's')
        ret = ft_putstr(va_arg(args, char *), ret);
    else if (c == 'd' || c == 'i')
        ret = ft_putnbr(va_arg(args, int), ret);
    else if (c == 'u')
        {
            u = va_arg(args, unsigned int);
            if (u < 0)
                u = 4294967296 + u;
            ret = ft_putnbr(u, ret);
        }
    else if (c == 'p')
        { 
            p = va_arg(args, unsigned long long);
            if (p == 0)
                ret = ft_putstr("(nil)", ret);
            else
            {
                ret = ft_putstr("0x", ret);
                ret = ft_puthex_ll(p, ret);
            }
        }
    else if (c == 'x')
        {
            u = va_arg(args, unsigned int);
            if (u == 0)
                ret = ft_putchar('0', ret);
            else
            {
                if (c == 'x')
                    ret = ft_puthex_ui(u, 0, ret);
                else
                    ret = ft_puthex_ui(u, 1, ret);
            }
        }
    else if (c == '%')
        ret = ft_putchar('%', ret);
    return ret;
}

int printer( char *str, va_list args)
{
    int ret;
    int i;

    i = 0;
    ret = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            ret = spec_check(args, str[i + 1], ret);
            i++;
        }
        else
            ret = ft_putchar(str[i], ret);    
        i++;
    }
    return ret;
}

int ft_printf(const char *str, ...)
{
    int ret;
    va_list args;

    ret = 0;
    if (!str)
        return 0;
    va_start(args, str);
    ret += printer((char *)str, args);
    va_end(args);
    return ret;
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *str;
    // str = malloc(1);
    printf("str -- %s", str);
}