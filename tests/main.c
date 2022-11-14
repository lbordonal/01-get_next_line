/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:33:12 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/14 16:24:02 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("../tests/harrypotter.txt", O_RDONLY);
	i = 1;
	while (i < 150)
	{
		line = get_next_line(fd);
		printf("%s", "line ");
		printf("%d", i);
		printf("%s", ": ");
		printf("%s", line);
		if (!line[fd])
			return (0);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
