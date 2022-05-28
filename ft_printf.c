/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:58:22 by gramiro-          #+#    #+#             */
/*   Updated: 2022/05/28 16:26:01 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		write (1, &str[x], 1);
		x++;
	}
	return (x);
}

int ft_putnbr(int n)
{
	int count;
	
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= - 1;
	}
	if (n <= 9)
	{
		count += ft_putchar(n + 48);
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return (count);
}

int ft_hexa(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n < 16)
		count += ft_putchar(base[n]);
	if (n >= 16)
	{
		count += ft_hexa(n / 16);
		count += ft_hexa(n % 16);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list arg;
	int		x;
	int		count;

	x = 0;
	count = 0;
	va_start (arg, str);
	while (str[x] != '\0')
	{
		if (str[x] == '%')
		{
			x++;
			if (str[x] == 'd')
				count += ft_putnbr(va_arg(arg, int));
			if (str[x] == 's')
				count += ft_putstr(va_arg(arg, char *));
			if (str[x] == 'x')
				count += ft_hexa(va_arg(arg, unsigned int));
		}
		else
			count += write(1, &str[x], 1);
		x++;
	}
	va_end (arg);
	return (count);
}

int main ()
{
	int len;
	int len2;
	len = ft_printf("S: %s D: %d X: %x\n", "ciao", -10, 16);
	len2= printf("S: %s D: %d X: %x\n", "ciao", -10, 16);
	printf("MIO: %d - VERO:  %d", len, len2);
}