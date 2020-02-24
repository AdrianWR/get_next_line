/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:30:38 by aroque            #+#    #+#             */
/*   Updated: 2020/02/24 18:11:57 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int i;
	int ret;
	int file;
	char *line;

	i = -1;
	if (argc == 3)
	{
		file = open(argv[1], O_RDONLY);
		while (++i < atoi(argv[2]))
		{
			ret = get_next_line(file, &line);
			if (ret > 0)
			{
				printf("%s\n", line);
				free(line);
			}
		}
		close(file);
	}
}
