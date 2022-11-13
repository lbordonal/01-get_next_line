/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:16:11 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/13 19:16:11 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;
	char	*line;

	fd = open("tests/test1.txt", O_RDONLY);
	i = 0;
	while (i < 15)
	{
		line = get_next_line(fd);
		printf("%s", "line ");
		printf("%d\n", i);
		printf("%s", line);
		if (line == NULL)
			break;
		free(line);
		i++;
	}
	return (0);
}
