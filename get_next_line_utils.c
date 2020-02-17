/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:30:01 by aroque            #+#    #+#             */
/*   Updated: 2020/02/17 18:15:47 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	if (!*s)
		return (0);
	return (ft_strlen(++s) + 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(join = malloc((len1 + len2 + 1) * sizeof(*join))))
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[len1++] = s2[i];
	join[len1] = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (!(substr = malloc((len + 1) * sizeof(*substr))))
		return (NULL);
	while ((i < len) && (start + i) < slen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
