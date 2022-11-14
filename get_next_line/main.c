/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:33:12 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/14 15:47:03 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/* int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("tests/J.K. Rowling - Harry Potter 1- Sorcerer's Stone.txt", O_RDONLY);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("Line [%02d]: %s", i, line);
		if (!line[fd])
			return (0);
//		free(line);
		i++;
	}
} */


/* int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("tests/test1.txt", O_RDONLY);
	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
 */

int	main(void)
{
	int		fd_1;
	int		i;
	char	*line[4096];

	i = 1;
	fd_1 = open("tests/J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt", \
					O_RDONLY);
	while (1)
	{
		line[fd_1] = get_next_line(fd_1);
		printf("Line %d for fd %d: %s\n", i, fd_1, line[fd_1]);
		if (!line[fd_1])
			return (0);
		free(line[fd_1]);
		i++;
	}
}
