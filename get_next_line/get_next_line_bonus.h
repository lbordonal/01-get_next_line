/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:20:54 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/15 15:48:37 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <fcntl.h>

/* #ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif */

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*read_and_save(int fd, char *save);
char	*get_line(char *save);
char	*ft_save(char *save);

void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(char *s);

#endif
