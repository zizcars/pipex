/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:03:38 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/02 18:10:54 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "mylib/get_next_line.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	int pipefd[2][2];
	pid_t pid[3];
	char *cmd1[] = {"sort", NULL};
	char *cmd2[] = {"uniq", "-u", NULL};
	char *cmd3[] = {"grep", "-v", "error", NULL};
	int i;

	i = 0;
	while (i < 2)
	{
		if(pipe(pipefd[i]) == -1)
		{
			perror("problem in pipe");
			exit(1);
		}
		i++;
	}
	pid[0] = fork();
	if (pid[0] == 0)
	{
		close(pipefd[0][0]);
		close(pipefd[1][0]);
		close(pipefd[1][1]);
		dup2(pipefd[0][1], STDOUT_FILENO);
		close(pipefd[0][1]);
		execve("/usr/bin/sort", cmd1, NULL);
		perror("execve");
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		close(pipefd[0][1]);
		close(pipefd[1][0]);
		dup2(pipefd[0][0], STDIN_FILENO);
		close(pipefd[0][0]);
		dup2(pipefd[1][1], STDOUT_FILENO);
		close(pipefd[1][1]);
		execve("/usr/bin/uniq", cmd2, NULL);
		perror("execve");
	}
	pid[2] = fork();
	if (pid[2] == 0)
	{
		close(pipefd[1][1]);
		close(pipefd[0][0]);
		close(pipefd[0][1]);
		dup2(pipefd[1][0], STDIN_FILENO);
		close(pipefd[1][0]);
		execve("/usr/bin/grep", cmd3, NULL);
		perror("execve");
	}
	else
	{

		int status;
		i = 0;
		while(i < 2)
		{
			close(pipefd[i][0]);
			close(pipefd[i][1]);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			waitpid(pid[i], &status, 0);
			i++;
		}
		exit(status);
	}
}