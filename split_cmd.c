/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:34 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/27 20:48:22 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int skip_space(char *str)
// {
// 	int spaces;
// 	spaces = 0;
// 	if (str == NULL)
// 		return (spaces);
// 	while ((str[spaces] >= 9 && str[spaces] <= 13) || str[spaces] == 32)
// 		spaces++;
// 	return (spaces);
// }

// void split_command(char *cmd, char **command, char **args)
// {
// 	int i;
// 	int len;
// 	if (cmd == NULL)
// 		return;
// 	cmd += skip_space(cmd);
// 	i = 0;
// 	while (cmd[i] && cmd[i] != ' ')
// 		i++;
// 	*command = malloc(sizeof(char) * (i + 1));
// 	if (*command == NULL)
// 		return;
// 	ft_strlcpy(*command, cmd, i + 1);
// 	cmd += i;
// 	cmd += skip_space(cmd);
// 	if (*cmd == '\0')
// 		return;
// 	len = ft_strlen(cmd);
// 	while (len != 0 && cmd[len - 1] == ' ')
// 		len--;
// 	*args = malloc(sizeof(char) * (len + 1));
// 	if (*args == NULL)
// 		return;
// 	ft_strlcpy(*args, cmd, len + 1);
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
			while(all_paths[i])
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

char *find_path_v2(char *command, char **env)
{
	char *p;

	p = env[2];
	while (*p != '=')
		p++;
	p++;
	return (path_(p, command, 0));
}

// #include <stdio.h>
// #include "libft/libft.h"
// int main(int argc, char **argv, char **env)
// {
// 	printf("path:|%s|\n", find_path_v2("ls", env));
// 	printf("path:|%s|\n", find_path_v2("cd", env));
// 	printf("path:|%s|\n", find_path_v2("pwd", env));
// 	printf("path:|%s|\n", find_path_v2("grep", env));
// 	printf("path:|%s|\n", find_path_v2("cldsdf", env));
// 	system("leaks a.out");
// }