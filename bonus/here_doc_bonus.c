/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:49:47 by achakkaf          #+#    #+#             */
/*   Updated: 2024/04/04 18:32:47 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int **open_pip(int ac)
{
	int **pipfd;
	int i;

	i = 0;
	pipfd = malloc((ac - 4) * sizeof(int *));
	while (pipfd && i < ac - 4)
	{
		pipfd[i] = malloc(2 * sizeof(int));
		if (pipfd[i] == NULL)
			return (NULL);
		if (pipe(pipfd[i]) == -1)
			print_error("I can't create a pipe\n");
		i++;
	}
	return (pipfd);
}

void close_all(int **pipfd, int ac)
{
	int i;

	i = 0;
	while (i < ac - 4)
	{
		close(pipfd[i][0]);
		close(pipfd[i][1]);
		free(pipfd[i]);
		i++;
	}
	free(pipfd);
}

void limiter_stop(char *limiter, int fd)
{
	char *line;
	char *tmp;

	line = NULL;
	if (limiter == NULL)
		print_error("There is no limiter\n");
	limiter = ft_strjoin(limiter, "\n");
	while (limiter)
	{
		tmp = line;
		line = get_next_line(STDIN);
		free(tmp);
		if (line == NULL)
			print_error("I find end of file\n");
		if (ft_strcmp(line, limiter) == 1)
			break;
		write(fd, line, ft_strlen(line));
	}
	free(line);
}

void cmd_1_here_doc(int ac, char **av, int **pipfd, char **env)
{
	int pid;

	pid = fork();
	if (pid < 0)
		print_error("I can't create child process");
	if (pid == 0)
	{
		limiter_stop(av[2], pipfd[0][1]);
		redirection(pipfd[0][0], STDIN);
		redirection(pipfd[1][1], STDOUT);
		close_all(pipfd, ac);
		exec_command(av[3], env);
	}
}

void last_cmd_here_doc(int ac, char **av, char **env, int **pipfd)
{
	int fd;
	int last_pipe;
	int pid;

	last_pipe = ac - 5;
	pid = fork();
	if (pid < 0)
		print_error("I can't create a child process\n");
	else if (pid == 0)
	{
		fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_NOFOLLOW | O_APPEND, 0644);
		if (fd < 0)
			print_error("I can't open output file\n");
		redirection(pipfd[last_pipe][0], STDIN);
		redirection(fd, STDOUT);
		close_all(pipfd, ac);
		close(fd);
		exec_command(av[ac - 2], env);
	}
}
