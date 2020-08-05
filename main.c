/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:45:21 by jhakonie          #+#    #+#             */
/*   Updated: 2020/08/05 23:28:20 by jhakonie         ###   ########.fr       */
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
	if (ac == 2 && ft_strcmp(av[1], "stdin") != 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			printf("open() failed\n");
		while (i < 100 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				printf("error\n");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
			}
			else if (x == 0)
			{
				printf("Nothing left to read.\n");
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
	}
	else if (ac == 1)
		printf("Too few arguments.\nTo test with echo, write:\necho 'some text' | ./test_gnl stdin\n");
	else if (ac == 2 && ft_strcmp(av[1], "stdin") == 0)
	{
		while (x == 1 && i < 10)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				ft_putstr("error\n");
			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
			}
			else if (x == 0)
			{
				printf("Nothing left to read.\n");
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
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
		while (i < 3 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				ft_putstr("error");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
			}
			else if (x == 0)
			{
				printf("Nothing left to read.\n");
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
		printf("fd is %d\n", fd);
		i = 0;
		while (i < 3 && x == 1)
		{
			x = get_next_line(fd2, &line);
			if (x == -1)
				ft_putstr("error\n");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
			}
			else if (x == 0)
			{
				printf("Nothing left to read.\n");
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
		i = 0;
		printf("fd is %d\n", fd2);
		while (i < 3 && x == 1)
		{
			x = get_next_line(fd3, &line);
			if (x == -1)
				ft_putstr("error");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
			}
			else if (x == 0)
			{
				printf("Nothing left to read.\n");
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
		i = 0;
		printf("fd is %d\n", fd3);
		while (i < 3 && x == 1)
		{
			x = get_next_line(fd, &line);
			if (x == -1)
				ft_putstr("error");

			else if (x == 1)
			{
				printf("Line is: |%s|\n", line);
				ft_strdel(&line);
			}
			else if (x == 0)
			{
				printf("Nothing left to read.\n");
				printf("Line is: |%s|\n", line);
			}
			i++;
		}
		printf("fd is %d\n", fd);

	}
	else
	{
		printf("wrong number of arguments, give 3 file names.\n");
	}

	// while (1)
	// 	;

	return (0);
}
