/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:23:30 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/01/01 12:59:24 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr(unsigned int u)
{
	int	count;

	count = 0;
	if (u < 10)
		count += ft_putchar(u + 48);
	else
	{
		count += ft_uputnbr(u / 10);
		count += ft_putchar(u % 10 + 48);
	}
	return (count);
}
