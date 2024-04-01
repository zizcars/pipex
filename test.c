/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:03:38 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/31 22:42:58 by achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "mylib/get_next_line.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	char *str;
	int i;
	int fd;

	i = 1;
	fd = open("infile.txt", O_RDWR);
	if (fd < 0)
		printf("ERROR");
	// printf("str:%s\n", get_next_line(fd));
	str = malloc(30);
	while(i)
	{
		i = read(fd, str, 20);
		printf("str:%s\n", str);
	}
	write(fd, "OK", 2);
}