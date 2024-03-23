/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tooles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:34:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/23 22:32:08 by Achakkaf         ###   ########.fr       */
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

/// @brief execute whereis command to find a path of a command
/// @param command
void exec_whereis(char *command)
{
	int fd;
	int dup_check;
	char *cmd[3];

	cmd[0] = "whereis";
	cmd[1] = command;
	cmd[2] = NULL;
	fd = open("path", O_CREAT | O_RDWR, 0666);
	if (fd < 0)
		error("can't open file in child");
	dup_check = dup2(fd, STDOUT);
	if (dup_check < 0)
		error("fieled in dup2");
	execve("/usr/bin/whereis", cmd, NULL);
	error("fieled in execve");
}

/// @brief find path of a command using whereis <command>
/// @param command
/// @param options
/// @return path of the command
char *find_path(char *command)
{
	pid_t pid;
	int fd;
	char *str;

	str = NULL;
	pid = fork();
	if (pid < 0)
		error("fork failed");
	else if (pid == 0)
		exec_whereis(command);
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

/// @brief execute a command
/// @param command 
void exec_command(char *command)
{
	char *cmd_path;
	char **cmd;
	
	cmd = ft_split(command, ' ');
	cmd_path = find_path(cmd[0]);
	cmd_path[ft_strlen(cmd_path) - 1] = '\0'; //remove /n from the path
	execve(cmd_path, cmd, NULL);
	error("Error in execve");
}

/// @brief redirection a file descriptor
/// @param new_fd 
/// @param old_fd 
void redirection(int new_fd, int old_fd)
{
	int check;
	
	check = dup2(new_fd, old_fd);
	if (check < 0)
		error("Error in dup2");
}
