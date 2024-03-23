/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:50:04 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/23 22:05:42 by Achakkaf         ###   ########.fr       */
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
	int fd[2]; //0: read and 1: write
	pid_t pid;

	if (pipe(fd) < 0)
		error("problem in pipe");
	pid = fork();
	if (pid < 0)
		error("problem in fork");
	else if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], "hello how are you", 18);
		close(fd[1]);
	}
	else
	{
		wait(NULL);
		char *com[] = {"cat", NULL};
		close(fd[1]);
		dup2(fd[0], STDIN);
		close(fd[0]);
		execve("/bin/cat", com, NULL);
		error("fieled in execve parent");
	}

}
