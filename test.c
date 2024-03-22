/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:50:04 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/22 20:27:10 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	pid_t pid;

	if (argc != 2)
		exit(1);
	pid = fork();
	if (pid < 0)
		perror("error");
	else if (pid == 0)
	{
		int fd;
		fd = open("path", O_CREAT, O_RDWR, 0666);
		if (errno)
		{
			perror("field to create path file");
			exit(1);
		}
		unlink("path");
		if (errno)
		{
			perror("field to unlink path file");
			exit(1);
		}
		fd = dup2(STROUT, fd);
		if (errno)
		{
			perror("field to dup2");
			exit(1);
		}
		char *com[] = {"/usr/bin/whereis", argv[1], NULL};
		execve("/usr/bin/whereis", com, NULL);
		if (errno)
		{
			perror("execve field");
			exit(1);
		}
		char *str = get_next_line(fd);
		ft_printf("%s", str);
	}
	else
	{
		int status;
		wait(&status);
		exit(status);
	}
}
