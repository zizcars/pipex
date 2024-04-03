/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:36:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/03 23:12:28 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int **open_pip(int ac)
{
	int **pipfd;
	int i;

	i = 0;
	pipfd = malloc((ac - 4) * sizeof(int *));
	while (pipfd && i < ac - 4)
	{
		pipfd[i] = malloc(2 * sizeof(int));
		if (pipfd[i] == NULL)
			return (NULL);
		if (pipe(pipfd[i]) == -1)
		{
			write(STDERR, "ERROR IN OPENING PIPES\n", 23);
			exit(1);
		}
		i++;
	}
	return (pipfd);
}

void close_all(int **pipfd, int ac)
{
	int i;

	i = 0;
	while (i < ac - 4)
	{
		close(pipfd[i][0]);
		close(pipfd[i][1]);
		free(pipfd[i]);
		i++;
	}
	free(pipfd);
}

void cmd_1(int ac, char **av, int **pipfd, char **env)
{
	int fd;
	int pid;

	pid = fork();
	if (pid < 0)
	{
		write(STDERR, "problem fork\n", 13);
		exit(1);
	}
	if (pid == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			write(STDERR, "CAN'T OPEN FILE", 15);
			exit(1);
		}
		redirection(fd, STDIN);
		redirection(pipfd[0][1], STDOUT);
		close_all(pipfd, ac);
		exec_command(av[2], env);
	}
}

void last_cmd(int ac, char **av, char **env, int **pipfd)
{
	int fd;
	int last_pipe;
	int pid;

	last_pipe = ac - 5;
	pid = fork();
	if (pid < 0)
	{
		write(STDERR, "CAN'T OPEN FILE", 15);
		exit(1);
	}
	else if (pid == 0)
	{
		fd = open(av[ac - 1], O_CREAT | O_WRONLY, 0644);
		if (fd < 0)
		{
			write(STDERR, "CAN'T OPEN FILE", 15);
			exit(1);
		}
		redirection(pipfd[last_pipe][0], STDIN);
		redirection(fd, STDOUT);
		close_all(pipfd, ac);
		exec_command(av[ac - 2], env);
	}
}

void cmd_n(int ac, char **av, char **env, int **pipfd)
{
	int i;
	int pip_i;
	int pid;

	pip_i = 0;
	i = 3;
	while (i < ac - 2)
	{
		pid = fork();
		if (pid < 0)
		{
			write(STDERR, "Problem fork\n", 13);
			exit(1);
		}
		else if (pid == 0)
		{
			redirection(pipfd[pip_i][0], STDIN);
			redirection(pipfd[pip_i + 1][1], STDOUT);
			close_all(pipfd, ac);
			exec_command(av[i], env);
		}
		i++;
		pip_i++;
	}
}

int main(int ac, char **av, char **env)
{
	int **pipfd;
	int i;

	if (ac < 6)
	{
		write(STDERR, "syntax error: <file1> <cmd1> ... <cmdn> <file2>\n", 48);
		exit(1);
	}
	i = 0;
	pipfd = open_pip(ac);
	cmd_1(ac, av, pipfd, env);
	cmd_n(ac, av, env, pipfd);
	last_cmd(ac, av, env, pipfd);
	close_all(pipfd, ac);
	i = 2;
	while (i < ac - 3)
	{
		wait(NULL);
		i++;
	}
}
