#include <unistd.h>
#include <stdarg.h>
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
	while (str[i])
	{
		ret = ft_putchar(str[i], ret);
		i++;
	}
	return ret;
}

int ft_putnbr(long n, int ret)
{
	if (n < 0)
	{
		n *= -1;
		ret = ft_putchar('-', ret);
		}
	if (n / 10 > 0)
	{
		ret = ft_putnbr(n / 10, ret);
	}
	ret = ft_putchar((n % 10) + 48, ret);
	return ret;
}

int ft_puthex_ll (unsigned long long p, int ret)
{
	unsigned long long rem;
	
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


int ft_puthex_ui (unsigned int x, int ret)
{
	unsigned int rem;
	
	if (x != 0)
	{
	
		rem = x % 16;
		ret = ft_puthex_ll(x / 16, ret);
		if (rem < 10)
			ret = ft_putchar(rem + 48, ret);
		else
			ret = ft_putchar(rem + 55 + 32, ret);
	}
	return ret;	
}

int spec_check(va_list args, char c, int ret)
{	
	char *s;
	unsigned int n;
	unsigned long long p;
	unsigned int x;
	
	n = 0;
	p = 0;
	x = 0;
	if (c == 'c')
		ret = ft_putchar(va_arg(args, int), ret);
	else if (c == 's')
	{
		s = va_arg(args, char *);
		if (s)
		{
			ret = ft_putstr(s, ret);
		}
		else 
			ret = ft_putstr("(null)",ret);		
	}
	else if (c == 'd' || c == 'i')
		ret = ft_putnbr(va_arg(args, int), ret);
	else if (c == 'u')
		{
			n = va_arg(args, unsigned int);
			ret = ft_putnbr(n,ret);	
		}
	else if (c == 'p')
		{
			p = va_arg(args, unsigned long long);
			if (p == 0)
				ret = ft_putchar('0', ret);
			else
			{	
				ret = ft_putstr("0x", ret);	
				ret = ft_puthex_ll(p ,ret);
			}
		}
	else if (c == 'x')
		{
			x = va_arg(args, unsigned int);
			if (x == 0)
				ret = ft_putchar('0', ret);
			else
				ret = ft_puthex_ui(x, ret);						
		}
	return ret;
}

int ft_printf(char *str, ...)
{
	int ret;
	int i;
	va_list args;
	
	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			{
				ret = spec_check(args, str[i+1], ret);	
				i++;	
			}
		else
			ret = ft_putchar(str[i], ret);
		i++;
	}
	va_end(args);
	return ret;
}

int main()
{	
	int i = 123;
	ft_printf("this is %p\n", 0);
	printf("this is %p",0);
}
