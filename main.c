/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:36:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/22 19:11:47 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *com_path(char *command)
{
	char *path;

	path = NULL;
	
	return (path);
}

int main(int argc, char **argv)
{
	if (argc != 5)
	{
		write(STRIN, "ERROR: ENTER 4 ARGMENTS\n", 25);
		exit(1);
	}
	char *file1, *file2, *cmd1, *cmd2;
	file1 = argv[1];
	file2 = argv[4];
	cmd1 = argv[2];
	cmd2 = argv[3];
	pid_t pid;

	open(file1, O_RDONLY);
	if (errno)
		perror("FILE ERROR");
	pid = fork();
	if(pid < 0)
		perror("ERROR IN FORK");
	else if (pid == 0)
	{
		
	}
	else 
	{
		int status;
		wait(&status);
		exit(status);
	}
}
