#include "ft_printf.h"

int ft_putchar(char c, int ret)
{   
    ret++;
    write(1, &c, 1);
    return ret;
}

int ft_putstr(char *str, int ret)
{
    int i;

    i = 0;
    if (str)
    {
    while (str[i])
        {
            ret = ft_putchar(str[i], ret);
            i++;
        }
    }
    else
        ret = ft_putstr("(null)", ret);
    return ret;
}

int ft_putnbr(long x, int ret)
{
    if (x < 0)
    {
        x = x * -1;
        ret = ft_putchar('-', ret);
    }
    if (x / 10 > 0)
        ret = ft_putnbr(x/10, ret);
    ret = ft_putchar((x % 10) + 48, ret);
    return ret;
}

int ft_puthex_ll(unsigned long long p, int ret)
{
    unsigned long long rem;
    int i;

    i = 0;
    if (p != 0)
    {
        rem = p % 16;
        ret = ft_puthex_ll(p / 16, ret);
        if (rem < 10)
            ret = ft_putchar(rem + 48, ret);
        else
            ret = ft_putchar(rem + 55 + 32, ret);
        }
    return ret;
}

int ft_puthex_ui(unsigned int p, int k, int ret)
{
    unsigned int rem;

    if (p != 0)
    {
        rem = p % 16;
        ret = ft_puthex_ui(p / 16, k, ret);
        if (rem < 10)
            ret = ft_putchar(rem + 48, ret);
        else
        {
            if (k == 0)
                ret = ft_putchar(rem + 55 + 32, ret);
            else
                ret = ft_putchar(rem + 55, ret);
        }
    }
    return ret;
}