/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:34 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/27 23:08:49 by Achakkaf         ###   ########.fr       */
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

// ls -la
// git status helep masdf
// ls
//

char *quotes_(char **command, int i)
{
	char *tmp;
	char *tmp2;

	while (command[i])
	{
		tmp2 = tmp;
		free(tmp2);
		tmp = ft_strjoin(tmp, command[i]);
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, " ");
		free(tmp2);
		i++;
	}
	tmp2 = tmp;
	tmp = ft_substr(tmp, 1, ft_strlen(tmp) - 3);
	free(tmp2);
	return (tmp);
}

// char **split_command(char *cmd)
// {
// 	char **rand_cmd;
// 	char **command;
// 	char *str;
// 	char *tmp;
// 	int count = 1;

// 	str = NULL;
// 	rand_cmd = ft_split(cmd, ' ');
// 	if (ft_strchr(rand_cmd[1], '-') && !(ft_strchr(rand_cmd[1], '"') || ft_strchr(rand_cmd[1], '\'')))
// 	{
// 		if (ft_strchr(rand_cmd[2], '"') || ft_strchr(rand_cmd[2], '\''))
// 			str = quotes_(command, 1);
// 	}
// 	else
// 	{
// 		if (ft_strchr(rand_cmd[1], '"') || ft_strchr(rand_cmd[1], '\''))
// 			str = quotes_(rand_cmd, 1);
		
// 	}
// }

#include <stdio.h>
#include "libft/libft.h"

int main(int argc, char **argv, char **env)
{
	char *cmd[] = {"\"hello", "how", "you\"", "sd",NULL};
	printf("%s\n", quotes_(cmd, 0));
	// system("leaks a.out");
}