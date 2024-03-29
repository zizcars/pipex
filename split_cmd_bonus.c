/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:34 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/29 22:47:04 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void skip_q(char *s, int *i)
{
	if (s[*i] == '\'' || s[*i] == '"')
	{
		(*i)++;
		while ((s[*i] != '\'' && s[*i] != '"') && s[*i])
			(*i)++;
	}
}

int new_cwords(char *s)
{
	int i;
	int count;
	int inword;

	i = 0;
	inword = 1;
	count = 0;
	while (s && s[i])
	{
		while (s[i] == ' ' && s[i])
			i++;
		while (s[i] != ' ' && s[i])
		{
			if (inword)
			{
				count++;
				inword = 0;
			}
			skip_q(s, &i);
			i++;
		}
		inword = 1;
	}
	return (count);
}

char *new_substr(char *str, int start, int end)
{
	char *sstr;
	int i;

	i = 0;
	if (str == NULL)
		return (NULL);
	sstr = malloc((end - start + 1) * sizeof(char));
	if (sstr == NULL)
		return (NULL);
	while (start < end && str[start])
	{
		sstr[i] = str[start];
		start++;
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}

char **split_cmd(char *command)
{
	char **cmd;
	int end;
	int start;
	int i;
	int in;

	in = 0;
	i = 0;
	end = 0;
	cmd = malloc((new_cwords(command) + 1) * sizeof(char *));
	while (cmd && command && command[end])
	{
		while (command[end] == ' ' && command[end])
			end++;
		start = end;
		while (command[end] != ' ' && command[end])
		{
			if (command[end] == '\'' || command[end] == '"')
			{
				start = ++end;
				while ((command[end] != '\'' && command[end] != '"') && command[end])
					end++;
				in = 1;
			}
			end++;
		}
		if (in && start != end)
		{
			cmd[i] = new_substr(command, start, end - 1);
			in = 0;
		}
		else if (start != end)
			cmd[i] = new_substr(command, start, end);
		else
			break;
		i++;
	}
	if (cmd)
		cmd[i] = NULL;
	return (cmd);
}
