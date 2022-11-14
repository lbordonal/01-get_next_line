/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:20:54 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/14 18:22:29 by lbordona         ###   ########.fr       */
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

# ifndef ARRAY_MAX_SIZE
#  define ARRAY_MAX_SIZE 4096
# endif

char	*get_next_line_bonus(int fd);
char	*read_and_save(int fd, char *save);
char	*get_line(char *save);
char	*ft_save(char *save);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlen(char *s);

#endif
