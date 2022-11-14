/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:22:00 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/14 15:37:26 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] && s[len] != '\n')
		len++;
	if (s && s[len] == '\n')
		len++;
	return (len);
}

int	ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	if (s && s[i] && s[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s2[0] == '\0')
		return (0);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && s2[j] != '\n')
		new[i++] = s2[j++];
	if (s2[j] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	if (s1)
		free(s1);
	return (new);
}

void	ft_strcpy(char *s1, char *s2)
{
	size_t	i;

	i = -1;
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = '\0';
}
