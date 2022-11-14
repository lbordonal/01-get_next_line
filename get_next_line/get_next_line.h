/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:20:54 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/14 11:34:06 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <fcntl.h>

/* #ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);

t_list	*ft_lstlast(t_list *lst);

void	*ft_strchr(const char *s, int c);
void	read_and_join(int fd, t_list **list, int *ptr_readed);
void	add_to_list(t_list **list, char *buffer, int readed);

int		find_newline(t_list *list);

#endif
