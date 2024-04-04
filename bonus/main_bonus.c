/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:36:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/04 18:38:41 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void print_error(char *str)
{
	write(STDERR, str, ft_strlen(str));
	exit(1);
}

void cmd_1(int ac, char **av, int **pipfd, char **env)
{
	int fd;
	int pid;

	pid = fork();
	if (pid < 0)
		print_error("can't create a child process\n");
	if (pid == 0)
	{
		fd = open(av[1], O_RDONLY | O_NOFOLLOW);
		if (fd < 0)
			print_error("can't open the input file\n");
		redirection(fd, STDIN);
		redirection(pipfd[0][1], STDOUT);
		close_all(pipfd, ac);
		close(fd);
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
		print_error("can't create a child process\n");
	else if (pid == 0)
	{
		fd = open(av[ac - 1], O_CREAT | O_NOFOLLOW |O_WRONLY, 0644);
		if (fd < 0)
			print_error("can't the create output file\n");
		redirection(pipfd[last_pipe][0], STDIN);
		redirection(fd, STDOUT);
		close_all(pipfd, ac);
		close(fd);
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
			print_error("can't create a child process\n");
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
		print_error("syntax error: file1 cmd1 ... cmdn file2\n");
	pipfd = open_pip(ac);
	if (ft_strcmp(av[1], "here_doc"))
	{
		cmd_1_here_doc(ac, av, pipfd, env);
		cmd_n(ac, av, env, pipfd);
		last_cmd_here_doc(ac, av, env, pipfd);
	}
	else
	{
		cmd_1(ac, av, pipfd, env);
		cmd_n(ac, av, env, pipfd);
		last_cmd(ac, av, env, pipfd);
	}
	close_all(pipfd, ac);
	i = 2;
	while (i < ac - 3)
	{
		wait(NULL); // i miss the children status;
		i++;
	}
}
