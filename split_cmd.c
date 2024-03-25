/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:34 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/25 18:19:45 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	skip_space(char *str)
{
	int spaces;

	spaces = 0;
	if(str == NULL)
		return (0);
	while ((str[spaces] >= 9 && str[spaces] <= 13) || str[spaces] == 32)
		spaces++;
	return (spaces);
}

void	split_command(char *cmd,char **command,char **args)
{
	int i;

	if (cmd ==  NULL)
		return;
	cmd += skip_space(cmd);
	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	*command = malloc(sizeof(char) * (i+1));
	if (*command == NULL)
		return;
	ft_strlcpy(*command, cmd, i+1);
	cmd += i;
	cmd += skip_space(cmd);
	if (*cmd == '\0')
		return;
	int len = ft_strlen(cmd);
	while (len != 0 && cmd[len - 1] == ' ')
		len--;
	*args = malloc(sizeof(char) * (len+1));
	if (*args == NULL)
		return;
	ft_strlcpy(*args, cmd, len+1);
}

// #include <stdio.h>
// #include "libft/libft.h"
// int main()
// {
// 	char *str = "awk {print $1}";
// 	char *command;
// 	char *args;
// 	split_command(str, &command, &args);
// 	// execve("/usr/bin/ls");
// 	printf("command:|%s|\nargs:|%s|\n", command, args);
// }