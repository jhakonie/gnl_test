/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:45:21 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/21 21:17:27 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int x = 1;
	size_t i = 0;

	line = NULL;
	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			printf("open() failed\n");
		while (i < 5 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				printf("error");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else
			{
				printf("Nothing left to read.\n");
			}
			i++;
		}
		printf("Line is: |%s|\n\n", line);
	}
	else if (ac == 1)
	{
		while (i < 5 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				ft_putstr("error");
			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else
			{
				printf("Nothing left to read.\n");
			}
			i++;
		}
		printf("Line is: |%s|\n", line);
	}
	else if (ac == 4)
	{

		fd = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		if (fd == -1)
			ft_putstr("open() failed\n");
		if (fd2 == -1)
			ft_putstr("open() failed\n");
		if (fd3 == -1)
			ft_putstr("open() failed\n");
		while (i < 2 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				ft_putstr("error");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else
			{
				printf("Nothing left to read.\n");
			}
			i++;
		}
		i = 0;
		while (i < 2 && x == 1)
		{
			x = get_next_line(fd2, &line);
			if (x == -1)
				ft_putstr("error");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else
			{
				printf("Nothing left to read.\n");
			}
			i++;
		}
		i = 0;
		while (i < 2 && x == 1)
		{
			x = get_next_line(fd3, &line);
			if (x == -1)
				ft_putstr("error");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else
			{
				printf("Nothing left to read.\n");
			}
			i++;
		}
		i = 0;
		while (i < 2 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				ft_putstr("error");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else
			{
				printf("Nothing left to read.\n");
			}
			i++;
		}
		printf("Line is: |%s|\n\n", line);
	}
	else
	{
		printf("wrong number of arguments");
	}

	// while (1)
	// 	;

	return (0);
}
