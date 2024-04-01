/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:36:40 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/31 22:39:22 by achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*store;
	int		i;

	i = 0;
	if (!s || ft_strlen(s) == 0)
		return (NULL);
	store = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!store)
		return (NULL);
	while (s[i])
	{
		store[i] = s[i];
		i++;
	}
	store[i] = '\0';
	return (store);
}
