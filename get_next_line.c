/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:50:29 by aroque            #+#    #+#             */
/*   Updated: 2020/02/17 19:41:16 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

//int		get_buffer(int fd, char **buffer)
//{
//	int		gnl;
//
//	if (!(*buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer))))
//		return (0);
//	gnl = read(fd, *buffer, BUFFER_SIZE);
//	(*buffer)[BUFFER_SIZE] = '\0';
//	return (gnl);
//}

int	get_next_line(int fd, char **line)
{
	int			rd;
	char		*tmp;
	char		*buffer;
	size_t		lsize;
	static char	*stock;

	tmp = NULL;
	stock = NULL;
	if (!stock)
	{
		if (!(stock = malloc(sizeof(*stock))))
			return (0);
		*stock = '\0';
	}
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer))))
		return (0);
	while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		tmp = ft_strjoin(stock, buffer);
		free(stock);
		stock = tmp;
		if (strchr(buffer, LBREAK))
			break;
	}
	lsize = 0;
	while (stock[lsize] != '\n')
		lsize++;
	//break_point = strchr(stock, LBREAK);
	//if (break_point)
	//	lsize = break_point - stock;
	//else
	//	lsize = 0;
	*line = ft_substr(stock, 0, lsize);
	//printf("lsize -> %lu\n", lsize);
	//printf("Stock -> %s\n", stock);
	//printf("Line -> %s\n", *line);
	//stock += max;
	//printf("Stock -> %s\n", stock);
	free(buffer);
	return (1);
}
