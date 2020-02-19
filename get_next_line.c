/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:50:29 by aroque            #+#    #+#             */
/*   Updated: 2020/02/19 18:09:38 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	print_line(int rd, char **heap, char **line)
{
	int			i;
	char		*tmp;

	i = 0;
	if (rd < 0)
		return (rd);
	else if (rd == 0 && *heap[0] == '\0')
		return (rd);
	while ((*heap)[i] != LBREAK || !(*heap)[i])
		i++;
	if ((*heap)[i] == LBREAK)
	{
		*line = ft_substr(*heap, 0, i);
		tmp = ft_strdup(*heap + i + 1);
		free(*heap);
		*heap = tmp;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			rd;
	char		*tmp;
	char		*buffer;
	static char	*heap;

	tmp = NULL;
	if (!heap)
	{
		if (!(heap = malloc(sizeof(*heap))))
			return (-1);
		*heap = '\0';
	}
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer))))
		return (-1);
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
