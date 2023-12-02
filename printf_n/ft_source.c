#include "ft_printf.h"

void ft_putchar(char c, int *result)
{
    write(1, &c, 1);
    *result += 1;
}

void ft_putstr(char *str, int *result)
{
    int i;
    i = 0;
    while(str[i])
    {
        ft_putchar(str[i], result);
        i++;
    }
}
void ft_putnbr(int i, int *result)
{
    if(i == -2147483648)
    {
        write(1, "-", 1);
        write(1, "2", 1);
        ft_putnbr(147483648, result);
    }
    if(i < 0)
    {
        write(1, "-", 1);
        i *= -1;
        ft_putnbr(i, result);
    }
    if(i >= 10)
    {
        ft_putnbr(i / 10, result);
        ft_putnbr(i % 10, result);
    }
    else
    {
        ft_putchar(i + '0', result);
    }
}
void ft_unsigned(unsigned int i, int *result)
{
    if(i >= 10)
    {
        ft_putnbr(i / 10, result);
        ft_putnbr(i % 10, result);
    }
    else
    {
        ft_putchar(i + '0', result);
    }
}
void	ft_dhex(unsigned int i, int *result)
{
	char	*base;

	base = "0123456789abcdef";
	if (i >= 16)
	{
		ft_dhex(i / 16, result);
		ft_dhex(i % 16, result);
	}
	else
		ft_putchar(base[i], result);
}

void	ft_uhex(unsigned int i, int *result)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (i >= 16)
	{
		ft_uhex(i / 16, result);
		ft_uhex(i % 16, result);
	}
	else
		ft_putchar(base[i], result);
}
void	ft_pointer(unsigned long a, int *result)
{
    char	*base;

	base = "0123456789abcdef";
	if (a >= 16)
	{
		ft_dhex(a / 16, result);
		ft_dhex(a % 16, result);
	}
	else
		ft_putchar(base[a], result);
}