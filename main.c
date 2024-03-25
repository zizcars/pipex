/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:36:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/25 22:42:06 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_proc(char **argv, int *pipfd)
{
	int fd;

	close(pipfd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("can't open file for stdin");
	redirection(fd, STDIN);
	redirection(pipfd[1], STDOUT);
	close(pipfd[1]);
	exec_command(argv[2]);
}

int main(int argc, char **argv)
{
	pid_t pid;
	int fd;
	int pipfd[2];

	if (argc != 5)
		exit(0);
	if (pipe(pipfd))
		error("problem in pipe");
	pid = fork();
	if (pid < 0)
		error("Error in fork <main>");
	else if (pid == 0)
		child_proc(argv, pipfd);
	else
	{
		wait(NULL);
		close(pipfd[1]);
		fd = open(argv[4], O_CREAT | O_RDWR, 0666);
		redirection(pipfd[0], STDIN);
		redirection(fd, STDOUT);
		close(pipfd[0]);
		// system("leaks pipex");
		exec_command(argv[3]);
	}
}
