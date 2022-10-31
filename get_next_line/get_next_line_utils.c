/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:07:50 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/30 15:07:55 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while(str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *stash, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (stach[i])
	{
		if (stash == c)
			return ((char *)&stash[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *buffer, char *stash)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = 0;
	if (!buffer)
	{
		buffer = malloc(sizeof(char ) * 1);
		buffer[0] = '/0'; 
	}
	if (!buffer || !stash)
		return (NULL);
	res = malloc(sizeof(char ) * (ft_strlen(buffer) + ft_strlen(stach) + 1));
	if (!res)
		return (NULL);
	if (buffer)
	{
		while (buffer[++i])
			res[i] = buffer[i];
	}
	while (stash[j])
	{
		res[i] = stash[j];
		i++;
		j++;
	}
	free(buffer);
	return (res);
}

char	*ft_get_line(char	*buffer)
{
	size_t	i;
	size_t	l;
	char	*line;

	i = 0;
	l = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i += 1;
	line = malloc(sizeof(char ) * (i + 1));
	while (i > l)
	{
		line[l] = buffer[l];
		l++;
	}
	line[l] = '\0';
	return (line); 
}

char	*ft_new_bufffer_start(char *buffer)
{
	
}