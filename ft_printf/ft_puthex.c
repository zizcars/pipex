/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:23:20 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/01/01 13:01:39 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	xputhex(unsigned int n)
{
	char	*xbasa;
	int		count;

	count = 0;
	xbasa = "0123456789abcdef";
	if (n < 16)
		count += ft_putchar(xbasa[n]);
	else
	{
		count += xputhex(n / 16);
		count += ft_putchar(xbasa[n % 16]);
	}
	return (count);
}

static int	x_puthex(unsigned int n)
{
	char	*x_base;
	int		count;

	count = 0;
	x_base = "0123456789ABCDEF";
	if (n < 16)
		count += ft_putchar(x_base[n]);
	else
	{
		count += x_puthex(n / 16);
		count += ft_putchar(x_base[n % 16]);
	}
	return (count);
}

int	ft_puthex(unsigned int n, char x)
{
	if (x == 'x')
		return (xputhex(n));
	else if (x == 'X')
		return (x_puthex(n));
	return (0);
}
