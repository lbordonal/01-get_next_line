/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:20:19 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/14 12:36:20 by lbordona         ###   ########.fr       */
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
	get_line(list, &line);
/* 3- Limpar a list */
	clean_line(&list);
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

/* get_line: pega os caracteres da list e coloca eles na line ate encontrar '\n' */
void	get_line(t_list *list, char **line)
{
	int	i;
	int	j;

	j = 0;
	if (!list)
		return (NULL);
	create_line(line, list);
	if (!line)
		return (NULL);
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				(*line)[j++] = list->content[i];
				break ;
			}
			(*line)[j++] = list->content[i++];
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}

/* create_line: calcula a quantidade de caracteres na line atual */
void	create_line(char **line, t_list *list)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		list = list->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/* clean_line: depois de ler a line, limpamos ela para ter somente as proximas na list */
void	clean_line(t_list **list)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!list || !clean_node)
		return (NULL);
	clean_node->next = NULL;
	last = ft_lstlast(*list);
	i = 0;
	while (last->content[i] && last->content != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_list(*list);
	*list = clean_node;
}

/* free_list: limpa a lista inteira*/
void	free_list(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
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
