/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:36:33 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/26 22:16:04 by Achakkaf         ###   ########.fr       */
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

# define STDIN 0
# define STDOUT 1
# define STDERR 2

char	*find_path(char *command);
int     skip_space(char *str);
void	error(char *error_message);
void    exec_command(char *command, char **env);
void    redirection(int new_fd, int old_fd);
void    split_command(char *cmd, char **command, char **args);

#endif