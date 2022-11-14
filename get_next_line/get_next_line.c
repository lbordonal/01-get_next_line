/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:20:19 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/14 15:36:52 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	next_line = ft_strjoin(0, line);
	if (ft_strchr(line, '\n') > -1)
	{
		ft_strcpy(line, &line[ft_strchr(line, '\n') + 1]);
		return (next_line);
	}
	i = read(fd, line, BUFFER_SIZE);
	while (i > 0)
	{
		line[i] = '\0';
		next_line = ft_strjoin(next_line, line);
		if (ft_strchr(line, '\n') > -1)
			break ;
		i = read(fd, line, BUFFER_SIZE);
	}
	ft_strcpy(line, &line[ft_strlen(line)]);
	return (next_line);
}
