/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:49:47 by achakkaf          #+#    #+#             */
/*   Updated: 2024/03/31 23:30:41 by achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*
	./pipex here_doc LIMITER cmd cmd1 file
	cmd << LIMITER | cmd1 >> file
*/

void limiter_stop(char *limiter)
{
	char *line;
	char *tmp;
	int onetime;

	onetime = 1;
	line = NULL;
	if (limiter == NULL)
	{
		write(STDERR, "limiter error\n", 15);
		exit(1);
	}
	while (ft_strcmp(line, limiter) == 0 || onetime)
	{
		if (onetime)
			onetime = 0;
		tmp = line;
		line = get_next_line(STDIN);
		free(tmp);
		if (line == NULL)
		{
			write(STDERR,"find end of file\n", 18);
			exit(1);
		}
		line[ft_strlen(line) - 1] = '\0';
	}
	free(line);
}


void end_file(int fd)
{
	char *str;
	int onetime;
	char *tmp;
	
	onetime = 1;
	str = NULL;
	while (str || onetime)
	{
		if(onetime)
			onetime = 0;
		tmp = str;
		str = get_next_line(fd);
		free(tmp);
	}
}

#include <stdio.h>
int main(int ac, char **av)
{
	// printf("%d\n", check_here_doc(av));
	int fd = open("infile.txt", O_RDWR);
	if (fd < 0)
		exit(1);
	end_file(fd);
	write(fd, "Yess!!!!",8);
}