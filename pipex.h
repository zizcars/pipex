/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:36:33 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/22 23:08:19 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include <errno.h>

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line.h"

# define STRIN 0
# define STROUT 1
# define STRERR 2

char	*find_path(char *command, char *options);
void	error(char *error_message);

#endif