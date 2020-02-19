/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:50:29 by aroque            #+#    #+#             */
/*   Updated: 2020/02/19 16:21:14 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>



int	get_next_line(int fd, char **line)
{
	int			rd;
	char		*tmp;
	char		*tmp2;
	char		*buffer;
	int			i;
	static char	*heap;

	tmp = NULL;
	if (!heap)
	{
		if (!(heap = malloc(sizeof(*heap))))
			return (0);
		*heap = '\0';
	}
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer))))
		return (0);
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
	i = 0;
	while (heap[i] != LBREAK || !heap[i])
		i++;
	if (!heap[i])
	{
		*line = ft_strdup(heap);
		return (0);
	}
	*line = ft_substr(heap, 0, i);
	tmp2 = ft_strdup(heap + i + 1);
	free(heap);
	heap = tmp2;
	return (1);
}
