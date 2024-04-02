/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:34:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/04/02 23:20:14 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/// @brief print error message using perror
/// @param error_massege
void error(char *error_message)
{
	perror(error_message);
	exit(1);
}

/// @brief execute whereis command to find a path of a command
/// @param command
// void exec_whereis(char *command)
// {
// 	int fd;
// 	int dup_check;
// 	char *cmd[3];
// 	cmd[0] = "whereis";
// 	cmd[1] = command;
// 	cmd[2] = NULL;
// 	fd = open("path", O_CREAT | O_WRONLY, 0777);
// 	if (fd < 0)
// 		error("can't creat path file");
// 	dup_check = dup2(fd, STDOUT);
// 	if (dup_check < 0)
// 		error("failed in dup2 in exec_whereis");
// 	execve("/usr/bin/whereis", cmd, NULL);
// 	error("can't execute whereis command whereis");
// }

/// @brief find path of a command using whereis <command>
/// @param command
/// @param options
/// @return path of the command
// char *find_path(char *command)
// {
// 	pid_t pid;
// 	int fd;
// 	char *str;
// 	int status;
// 	str = NULL;
// 	pid = fork();
// 	if (pid < 0)
// 		error("fork failed in find_path");
// 	else if (pid == 0)
// 		exec_whereis(command);
// 	else
// 	{
// 		wait(&status);
// 		if (status != 0)
// 			exit(status);
// 		fd = open("path", O_RDONLY);
// 		if (fd < 0)
// 			error("file path not found");
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			error("command not found");
// 		close(fd);
// 		// unlink("path");
// 	}
// 	return (str);
// }

char *path_(char *p, char *command, int i)
{
	char **all_paths;
	char *path;
	char *tmp;

	all_paths = ft_split(p, ':');
	while (all_paths[i])
	{
		path = ft_strjoin(all_paths[i], "/");
		free(all_paths[i]);
		tmp = path;
		path = ft_strjoin(path, command);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			while (all_paths[i])
				free(all_paths[++i]);
			free(all_paths);
			return (path);
		}
		free(path);
		path = NULL;
		i++;
	}
	free(all_paths);
	return (NULL);
}

char *find_path(char *command, char **env)
{
	char *p;
	char *path;
	int i;
	int j;

	i = 0;
	j = 0;
	path = "PATH=";
	while (env[i])
	{
		while (env[i][j] == path[j] && path[j])
			j++;
		if (path[j] == '\0')
			break;
		i++;
	}
	p = env[i];
	p += j;
	return (path_(p, command, 0));
}

/// @brief execute a command
/// @param command
void exec_command(char *command, char **env)
{
	char *cmd_path;
	char **cmd;

	cmd = split_cmd(command);
	cmd_path = find_path(cmd[0], env);
	execve(cmd_path, cmd, env);
	error("execve:");
}

/// @brief redirection a file descriptor
/// @param new_fd
/// @param old_fd
void redirection(int new_fd, int old_fd)
{
	int check;

	check = dup2(new_fd, old_fd);
	if (check < 0)
		error("can't dup2 in redirection");
}
