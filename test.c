/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:33:01 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/27 21:04:41 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

int main(int ac, char **av, char **env)
{
	// exec_command(av[1], env);
	char *cmd[4] = {"git", "add", ".", NULL};

	
	execve("/usr/bin/git", cmd, NULL);
	// printf("%s\n", env[0]);
	// printf("%s\n", env[1]);
	// printf("%s\n", env[2]);
}
