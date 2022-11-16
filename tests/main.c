/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:33:12 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/16 10:39:10 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("../tests/miranha.txt", O_RDONLY);
	//fd = open("../tests/simpsons.txt", O_RDONLY);
	//fd = open("../tests/hp.txt", O_RDONLY);
	//fd = open("../tests/test1.txt", O_RDONLY);
	//fd = open("../tests/big_line_with_nl", O_RDONLY);
	//fd = open("../tests/big_line_no_nl", O_RDONLY);
	i = 1;
	while (get_next_line(fd))
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
