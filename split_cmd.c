/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:34 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/23 23:02:54 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	skip_space(char *str)
{
	int spaces;

	spaces = 0;
	while (str[spaces] && str[spaces] == ' ')
		spaces++;
	return (spaces);
}
int count_words(char *str)
{
	int i; //|hwlf ssdf  |
	int j;
	int count;

	count = 0;
	i = 0;
	while(str[i])
	{
		while(str[i] && str[i] == ' ')
			i++;
		j = i;
		while(str[j] && str[j] != ' ')
			j++;
		if (j - i > 0)
			count++;
		if (count > 1)
			return (count);
		i = j;
	}
	return (count);
}
// char	**split_cmd(char *command)
// {
// 	char **cmd;
// 	int i;
// 	int spaces;
// 	int n;

// 	n = 2;
// 	spaces = 0;
// 	i = 0;
// 	command += skip_space(command);
// 	while (command[i] && command[i] != ' ')
// 		i++;
// 	if (command[i] != '\0')
// 		n = 3;
// 	cmd = malloc(sizeof(char *) * n);
// 	ft_substr(command, 0, i);
// }
#include <stdio.h>
int main()
{
	printf("%d\n", count_words("hello word"));
	printf("%d\n", count_words("    hello word    "));
	printf("%d\n", count_words("    hello word"));
	printf("%d\n", count_words("hello word     "));
}