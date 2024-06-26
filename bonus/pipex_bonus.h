/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:36:33 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/04 20:25:10 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

# include "../mylib/ft_printf.h"
# include "../mylib/libft.h"
# include "../mylib/get_next_line.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

char	*find_path(char *command, char **env);
char	**split_cmd(char *command);
void	error(char *error_message);
void	exec_command(char *command, char **env);
void	redirection(int new_fd, int old_fd);
int		**open_pip(int ac);
void	close_all(int **pipfd, int ac);
void	print_error(char *str);
void	limiter_stop(char *limiter, int fd);
void	cmd_1_here_doc(int ac, char **av, int **pipfd, char **env);
void	last_cmd_here_doc(int ac, char **av, char **env, int **pipfd);
#endif