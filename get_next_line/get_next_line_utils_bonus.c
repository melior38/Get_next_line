/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:26:09 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/02 02:26:10 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *stash, int c)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == c)
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
		buffer = ft_calloc(sizeof(char ), 1);
	if (!buffer || !stash)
		return (NULL);
	res = ft_calloc(sizeof(char ), (ft_strlen(buffer) + ft_strlen(stash) + 1));
	if (!res)
		return (NULL);
	if (buffer)
	{
		while (buffer[++i])
			res[i] = buffer[i];
	}
	while (stash[j])
	{
		res[i++] = stash[j++];
	}
	free(buffer);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		*(ptr++) = '\0';
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}
