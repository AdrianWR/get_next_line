/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:50:29 by aroque            #+#    #+#             */
/*   Updated: 2020/02/20 11:45:02 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

static int	print_line(int rd, char **heap, char **line)
{
	int			i;
	char		*tmp;

	i = 0;
	if (rd < 0)
		return (GNL_FAILURE);
	else if (rd == 0 && *heap[0] == '\0')
		return (GNL_EOF);
	while ((*heap)[i] != LBREAK && (*heap)[i] != '\0')
		i++;
	if ((*heap)[i] == LBREAK)
	{
		*line = ft_substr(*heap, 0, i);
		tmp = ft_strdup(*heap + i + 1);
		free(*heap);
		*heap = tmp;
	}
	else
	{
		*line = ft_strdup(*heap);
	}
	if ((*heap)[0] == '\0')
	{
		ft_strdel(heap);
	}
	return (GNL_SUCCESS);
}

int	get_next_line(int fd, char **line)
{
	int			rd;
	char		*tmp;
	char		*buffer;
	static char	*heap;

	tmp = NULL;
	if (fd < 0 || !line)
		return (GNL_FAILURE);
	if (!heap)
	{
		if (!(heap = malloc(sizeof(*heap))))
			return (GNL_FAILURE);
		*heap = '\0';
	}
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer))))
		return (GNL_FAILURE);
	while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		tmp = ft_strjoin(heap, buffer);
		free(heap);
		heap = tmp;
		if (ft_strchr(buffer, LBREAK))
			break;
	}
	free(buffer);
	return (print_line(rd, &heap, line));
}
