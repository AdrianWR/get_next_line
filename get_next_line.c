/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:50:29 by aroque            #+#    #+#             */
/*   Updated: 2020/02/14 16:43:47 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static 

int	get_next_line(int fd, char **line)
{
	int	gnl;
	char *buffer;

	while ((gnl = read(fd, buffer, BUFFER_SIZE)))
	{

	}
	gnl = read(fd, buffer, BUFFER_SIZE);
	line[BUFFER_SIZE + 1] = '\0';
	if (gnl < 1)
		return (gnl);
	return (1);
}
