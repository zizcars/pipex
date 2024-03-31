/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:23:23 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/01/01 12:57:14 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		n = -n;
		count += ft_putchar('-');
	}
	if (n < 10)
		count += ft_putchar(n + 48);
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + 48);
	}
	return (count);
}
