/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:36:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/29 23:07:39 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void first_child(char **argv, int *pipfd, char **env)
{
	int fd;

	close(pipfd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("can't open file for STDIN");
	redirection(fd, STDIN);
	redirection(pipfd[1], STDOUT);
	close(pipfd[1]);
	close(fd);
	exec_command(argv[2], env);
}

void last_child(char **argv,int argc ,int *pipfd, char **env)
{
	int fd;

	fd = open(argv[argc - 1], O_CREAT | O_WRONLY, 0666);
	if (fd < 0)
		error("can't open file 4 in main");
	close(pipfd[1]);
	redirection(fd, STDOUT);
	redirection(pipfd[0], STDIN);
	close(pipfd[0]);
	close(fd);
	exec_command(argv[3], env);
}

void c_child(pid_t *child)
{
	*child = fork();
	if (*child < 0)
		error("fork1 error in main");
}

int main(int argc, char **argv, char **env)
{
	pid_t child;
	int pipfd[2];
	int status;
	int i;

	i = 2;
	if (pipe(pipfd))
		error("pipe error in main");
	c_child(&child);
	if (child == 0)
		first_child(argv, pipfd, env);
	// while(i < argc - 1)
	// {
	// 	c_child(&child);
	// 	close(pipfd[1]);
	// 	redirection(pipfd[0], STDIN);
	// 	close(pipfd[0]);
	// 	exec_command(argv[i], env);
	// 	i++;
	// }
	c_child(&child);
	if (child == 0)
		last_child(argv,argc ,pipfd, env);
	else
	{
		close(pipfd[0]);
		close(pipfd[1]);
		waitpid(child, &status, 0);
		// waitpid(child2, &status, 0);
		if (status < 0)
			error("There is a problem");
	}
}
