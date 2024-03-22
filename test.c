/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:50:04 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/22 22:54:45 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error(char *error_massege)
{
	perror(error_massege);
	exit(1);
}
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
		int dup_check;
	
		fd = open("path", O_CREAT | O_RDWR, 0666);
		if (fd < 0)
			error("can't open file in child");
		dup_check = dup2(fd, STROUT);
		if (dup_check < 0)
			error("fieled in dup2");
		char *com[] = {"/usr/bin/whereis", argv[1], NULL};
		execve("/usr/bin/whereis", com, NULL);
		error("fieled in execve");
	}
	else
	{
		int fd;
		fd = open("path", O_CREAT | O_RDWR, 0666);
		if (fd < 0)
			error("can't open file prant");
		waitpid(pid, NULL, 0);
		char *str = get_next_line(fd);
		ft_printf("%s", str);
		close(fd);
		unlink("path");
	}
}
