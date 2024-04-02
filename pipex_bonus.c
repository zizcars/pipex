/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:36:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/02 23:17:13 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// int **open_pipes(int ac)
// {
// 	int pipes;
// 	int pipefd[ac - 4][2];
// 	int i;
// 	i = 0;
// 	pipes = ac - 4;
// 	while (i < pipes)
// 	{
// 		if (pipe(pipefd[i]) == -1)
// 			error("error in pipes");
// 		i++;
// 	}
// }

void close_pipes(int ac, int **pipfd)
{
	int i;

	i = 0;
	while (i < ac - 4)
	{
		close(pipfd[i][0]);
		close(pipfd[i][1]);
		i++;
	}
}

void first_child(int ac, char **av, int **pipfd, char **env)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error("can't open file for STDIN");
	
	redirection(fd, STDIN);
	redirection(pipfd[0][1], STDOUT);
	close_pipes(ac, pipfd);
	close(fd);
	exec_command(av[2], env);
}

// void child_n(int ac, char **av, int **pipfd, int pip_i, char **env)
// {
// 	redirection(pipfd[pip_i][0], STDIN);
// 	redirection(pipfd[pip_i + 1][1], STDOUT);
// 	close_pipes(pipfd, ac);
// 	exec_command(av[]);
// }

void last_child(int ac, char **av, int **pipfd, char **env)
{
	int fd;

	fd = open(av[ac - 1], O_CREAT | O_WRONLY, 0666);
	if (fd < 0)
		error("can't open file 4 in main");
	redirection(pipfd[ac - 5][0], STDIN);
	redirection(fd, STDOUT);
	close_pipes(ac, pipfd);
	close(fd);
	exec_command(av[ac - 2], env);
}

void c_child(pid_t *child)
{
	*child = fork();
	if (*child < 0)
		error("fork1 error in main");
}

/*  0       1   2    3     3        n   n + 1   argc = n + 2
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
./pipex file1 cmd1 cmd2 file2
*/

int main(int ac, char **av, char **env)
{
	int **pipfd;
	int i;
	pid_t pid[ac - 3];
	int pid_i;
	int cmd_i;

	pid_i = 0;
	i = 0;
	pipfd = malloc((ac - 4) * sizeof(int));
	while (i < ac - 4)
	{
		pipfd[i] = malloc(2 * sizeof(int));
		if (pipe(pipfd[i]))
			error("error in pipes");
		i++;
	}
	c_child(&pid[pid_i]);
	if (pid[pid_i] == 0)
		first_child(ac, av, pipfd, env);
	pid_i++;
	cmd_i = 0;
	i = 0;
	while (cmd_i < ac - 5)
	{
		pid_i++;
		c_child(&pid[pid_i]);
		if (pid[pid_i] == 0)
		{
			ft_printf("pid: %d\n", i);
			redirection(pipfd[i][0], STDIN);
			redirection(pipfd[i + 1][1], STDOUT);
			close_pipes(ac, pipfd);
			exec_command(av[cmd_i + 3], env);
		}
		cmd_i++;
		i++;
	}
	c_child(&pid[pid_i]);
	if (pid[pid_i] == 0)
		last_child(ac, av, pipfd, env);
	pid_i++;
	if (pid[pid_i] != 0)
	{
		i = 0;
		while (i < ac - 4)
		{
			close(pipfd[i][0]);
			close(pipfd[i][1]);
			i++;
		}
		i = 0;
		int status;
		while (i < pid_i)
		{
			waitpid(pid[i++], &status, 0);
			if (status < 0)
				exit(status);
		}
		
	}
}
