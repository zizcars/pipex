/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:36:33 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/31 22:30:12 by achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

#include "mylib/ft_printf.h"
#include "mylib/libft.h"
#include "mylib/get_next_line.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2

char *find_path(char *command, char **env);
char **split_cmd(char *command);
void error(char *error_message);
void exec_command(char *command, char **env);
void redirection(int new_fd, int old_fd);

#endif