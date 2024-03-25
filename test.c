/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:50:04 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/25 22:20:04 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error(char *error_massege)
{
	perror(error_massege);
	exit(1);
}
int main()
{
	// int fd[2]; //0: read and 1: write
	pid_t pid;

	// if (pipe(fd) < 0)
	// 	error("problem in pipe");
	pid = fork();
	if (pid < 0)
		error("problem in fork");
	// else if (pid == 0)
	// {
	// 	close(fd[0]);
	// 	write(fd[1], "hello how are you", 18);
	// 	close(fd[1]);
	// }
	// else
	// {
		// wait(NULL);
	// int fd = open("oufile.txt", O_RDWR);
	char *com[] = {"--version", NULL};
	// close(fd[1]);
	// dup2(fd, STDOUT);
	// close(fd[0]);
	execve("/usr/bin/python", com, NULL);
	error("fieled in execve parent");
	// }

}
