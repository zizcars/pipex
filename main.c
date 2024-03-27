/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:36:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/26 21:58:45 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_proc(char **argv, int *pipfd, char **env)
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

int main(int argc, char **argv, char **env)
{
	pid_t child1;
	pid_t child2;
	int fd;
	int pipfd[2];

	if (argc != 5)
		exit(0);
	if (pipe(pipfd))
		error("pipe error in main");
	child1 = fork();
	if (child1 < 0)
		error("fork1 error in main");
	else if (child1 == 0)
		child_proc(argv, pipfd, env);
	child2 = fork();
	if (child2 < 0)
		error("fork1 error in main");
	else if (child2 == 0)
	{
		// wait(NULL);
		waitpid(child1, NULL, 0);
		fd = open(argv[4], O_CREAT | O_WRONLY, 0666);
		if (fd < 0)
			error("can't open file 4 in main");
		close(pipfd[1]);
		redirection(fd, STDOUT);
		redirection(pipfd[0], STDIN);
		close(pipfd[0]);
		close(fd);
		exec_command(argv[3], env);
	}
	else
	{
		int status;
		close(pipfd[0]);
		close(pipfd[1]);
		waitpid(child1, &status, 0);
		waitpid(child2, &status, 0);
		
		if (status < 0)
			error("there is a problem");
	}
}
