/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:30:38 by aroque            #+#    #+#             */
/*   Updated: 2020/02/16 21:32:42 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int file;
	int gnl;
	char *line;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		printf("File: %d\n", file);
		gnl = get_next_line(file, &line);
		printf("Retorno: %d\n", gnl);
		printf("%s\n", line);
	}
}
