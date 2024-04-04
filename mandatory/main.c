/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:36:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/04 20:11:32 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **argv, int *pipfd, char **env)
{
	int	fd;

	close(pipfd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("The input file not found\n");
	redirection(fd, STDIN);
	redirection(pipfd[1], STDOUT);
	close(pipfd[1]);
	close(fd);
	exec_command(argv[2], env);
}

void	last_child(char **argv, int *pipfd, char **env)
{
	int	fd;

	fd = open(argv[4], O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		error("The output file not found\n");
	close(pipfd[1]);
	redirection(fd, STDOUT);
	redirection(pipfd[0], STDIN);
	close(pipfd[0]);
	close(fd);
	exec_command(argv[3], env);
}

void	c_child(pid_t *child)
{
	*child = fork();
	if (*child < 0)
		error("I can't create a child process\n");
}

int	main(int argc, char **argv, char **env)
{
	pid_t	child1;
	pid_t	child2;
	int		pipfd[2];

	if (argc != 5)
		error("syntax error: file1 cmd1 cmd2 file2\n");
	if (pipe(pipfd))
		error("pipe error\n");
	c_child(&child1);
	if (child1 == 0)
		first_child(argv, pipfd, env);
	c_child(&child2);
	if (child2 == 0)
		last_child(argv, pipfd, env);
	else
	{
		close(pipfd[0]);
		close(pipfd[1]);
		waitpid(child1, NULL, 0);
		waitpid(child2, NULL, 0);
	}
}
