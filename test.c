/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:30:38 by aroque            #+#    #+#             */
/*   Updated: 2020/02/17 17:59:32 by aroque           ###   ########.fr       */
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
	char *line;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		get_next_line(file, &line);
		printf("%s\n", line);
		free(line);
		get_next_line(file, &line);
		printf("%s\n", line);
		free(line);
	}
}
