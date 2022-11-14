/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:20:19 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/14 11:41:47 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	int				readed;
	int				is_readable;

	list = NULL;
	line = NULL;
	readed = 1;
	is_readable = read (fd, &line, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || is_readable < 0)
		return (NULL);
/* 1- Ler fd por read e adicionar a list */
	read_and_join(fd, &list, &readed);
	if (!list)
		return (NULL);
/* 2- Extrair de list para line */

/* 3- Limpar a list */

	return (line);
}

/* read_and_join: usa read para ler os caracteres e adiciona-los na list */
void	read_and_join(int fd, t_list **list, int *ptr_readed)
{
	char	*buffer;

	while (find_newline(*list) == 0 && ptr_readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		*ptr_readed = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*list == NULL && ptr_readed == 0) || ptr_readed == -1)
		{
			free (buffer);
			return ;
		}
		buffer[*ptr_readed] = '\0';
		add_to_list(list, buffer, *ptr_readed);
		free (buffer);
	}
}

/* find_newline: procura por '\n' na list
	se encontrar = 1, se nao encontrar = 0 */
int	find_newline(t_list *list)
{
	int		i;
	t_list	*current;

	i = 0;
	if (!list)
		return (0);
	current = ft_lstlast(list);
	while (current->content[i])
	{
		if (current->content == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* add_to_list: adiciona o conteudo do buffer no fim da lista
	(mistura de ft_lstnew com ft_lstadd_back) */
void	add_to_list(t_list **list, char *buffer, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new;

	i = 0;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = malloc(sizeof(char) * (readed + 1));
	if (!new->content)
		return (NULL);
	while (buffer[i] && i < readed)
	{
		new->content[i] = buffer[i];
		i++;
	}
	new->content[i] = '\0';
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = ft_lstlast(list);
	last->next = new;
}

/* int	main(void)
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
} */
