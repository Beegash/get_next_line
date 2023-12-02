#include "ft_printf.h"

void ft_check(va_list *list, char n, int *result)
{
    if(n == 'c')
    {
        ft_putchar(va_arg(*list, int), result);
    }
    else if(n == 's')
    {
        ft_putstr(va_arg(*list, char *), result);
    }
    else if(n == 'p')
    {
        ft_putstr("0x", result);
        ft_pointer(va_arg(*list, unsigned long), result);
    }
    else if(n == 'd' || n == 'i')
    {
        ft_putnbr(va_arg(*list, int), result);
    }
    else if(n == 'u')
    {
        ft_unsigned(va_arg(*list, unsigned int), result);
    }
    else if(n == 'x')
    {
        ft_dhex(va_arg(*list, unsigned int), result);
    }
    else if(n == 'X')
    {
        ft_uhex(va_arg(*list, unsigned int), result);
    }
    else if(n == '%')
    {
        ft_putchar('%', result);
    }
}
int ft_printf(const char *s, ...)
{
    int i;
    int result;
    va_list list;

    i = 0;
    result = 0;
    va_start(list, s);
    while(s[i] && s)
    {
        if(s[i] == '%' && s[i + 1])
        {
            ft_check(&list, s[++i], &result);
        }
        else
        {
            ft_putchar(s[i], &result);
        }
        i++;
    }
    va_end(list);
    return 1;
}