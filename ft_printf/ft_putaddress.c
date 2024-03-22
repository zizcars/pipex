/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:55:59 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/01/01 18:40:56 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(void *address)
{
	char			*xbasa;
	int				count;
	unsigned long	x;

	x = (unsigned long)address;
	count = 0;
	xbasa = "0123456789abcdef";
	if (x < 16)
		count += ft_putchar(xbasa[x]);
	else
	{
		count += ft_putaddress((void *)(x / 16));
		count += ft_putchar(xbasa[x % 16]);
	}
	return (count);
}
