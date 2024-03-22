/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tooles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:34:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/22 23:13:50 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief print error message using perror
/// @param error_massege
void error(char *error_message)
{
	perror(error_message);
	exit(1);
}

/// @brief find path of a command using whereis <command>
/// @param command 
/// @param options 
/// @return path of the command
char *find_path(char *command, char *options)
{
	pid_t pid;
	int fd;
	char *str;

	str = NULL;
	pid = fork();
	if (pid < 0)
		error("fork failed");
	else if (pid == 0)
	{
		int dup_check;
	
		fd = open("path", O_CREAT | O_RDWR, 0666);
		if (fd < 0)
			error("can't open file in child");
		dup_check = dup2(fd, STROUT);
		if (dup_check < 0)
			error("fieled in dup2");
		char *com[] = {"/usr/bin/whereis", command, options, NULL};
		execve("/usr/bin/whereis", com, NULL);
		error("fieled in execve");
	}
	else
	{
		fd = open("path", O_CREAT | O_RDWR, 0666);
		if (fd < 0)
			error("can't open file prent");
		waitpid(pid, NULL, 0);
		str = get_next_line(fd);
		close(fd);
		unlink("path");
	}
	return (str);
}
