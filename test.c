/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:03:38 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/03 21:19:39 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av, char **env)
{
	int pipfd[ac - 4][2];
	int pip_i;
	int i;
	int pip;
	int j;

	i = 0;
	while (i < ac - 4)
		pipe(pipfd[i++]);
	pip_i = 0;
	pip = 0;
	if (fork() == 0)
	{
		int fd;

		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			write(STDERR, "CAN'T OPEN FILE", 15);
			exit(1);
		}
		redirection(fd, STDIN);
		redirection(pipfd[0][1], STDOUT);
		j = 0;
		while (j < ac - 4)
		{
			close(pipfd[j][0]);
			close(pipfd[j][1]);
			j++;
		}
		exec_command(av[2], env);
	}
	i = 3;
	while (i < ac - 2)
	{
		if (fork() == 0)
		{
			redirection(pipfd[pip_i][0], STDIN);
			redirection(pipfd[pip_i + 1][1], STDOUT);
			j = 0;
			while (j < ac - 4)
			{
				close(pipfd[j][0]);
				close(pipfd[j][1]);
				j++;
			}
			exec_command(av[i], env);
		}
		i++;
		pip_i++;
	}
	if (fork() == 0)
	{
		int fd;

		fd = open(av[ac - 1], O_CREAT | O_WRONLY, 0666);
		if (fd < 0)
		{
			write(STDERR, "CAN'T OPEN FILE", 15);
			exit(1);
		}
		redirection(pipfd[pip_i][0], STDIN);
		redirection(fd, STDOUT);
		j = 0;
		while (j < ac - 4)
		{
			close(pipfd[j][0]);
			close(pipfd[j][1]);
			j++;
		}
		exec_command(av[i], env);
	}
	j = 0;
	while (j < ac - 4)
	{
		close(pipfd[j][0]);
		close(pipfd[j][1]);
		j++;
	}
	i = 2;
	while (i < ac - 3)
	{
		wait(NULL);
		i++;
	}
}