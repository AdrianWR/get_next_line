/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:50:29 by aroque            #+#    #+#             */
/*   Updated: 2020/02/16 21:32:39 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

char	*get_buffer(fd)
{
	int		gnl;
	char	*buffer;

	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer))))
		return (NULL);
	gnl = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	return (buffer);
}

int	get_next_line(int fd, char **line)
{
	int i;
	//int end;
	char *buffer;

	i = 0;
	*line = malloc(BUFFER_SIZE + 1);
	buffer = get_buffer(fd);
	printf("Buffer: %s\n", buffer);
	while (!memccpy(*line, buffer, LBREAK, BUFFER_SIZE))
	{
		buffer = get_buffer(fd);
		
	}
	//end = ((char *)- *line);
	//printf("end: %d\n", end);
	//(*line)[10] = '\0';
	printf("line: %s\n", *line);
	//*line[i + 1] = '\0';
	//if (gnl < 1)
	//	return (gnl);
	return (1);
}
