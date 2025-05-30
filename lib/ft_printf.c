/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:23:03 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/01/03 13:23:14 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(va_list ap, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putaddress(va_arg(ap, void *)) + 2);
	}
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), c));
	if (c == 'u')
		return (ft_uputnbr(va_arg(ap, unsigned int)));
	return (0);
}

static int	ft_printf_checker(const char *format, va_list ap, char *conversions)
{
	int	count;
	int	i;

	count = 0;
	while (*format)
	{
		i = 0;
		while (*format != '%' && *format)
			count += ft_putchar(*format++);
		if (*format == '%')
		{
			while (*(format + 1) != conversions[i])
				i++ ;
			count += check(ap, *(format + 1));
			format += 2;
		}
		else
			break ;
	}
	va_end(ap);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*conversions;

	conversions = "cspdiuxX%";
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(ap, format);
	if (!ft_strchr(format, '%'))
		return (ft_putstr((void *)format));
	return (ft_printf_checker(format, ap, conversions));
}
