/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:07:30 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/30 15:07:32 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <sys/types.h> //ssize_t library
#include <unistd.h>

int	ft_read_till_sep(int fd, char **buffer)
{
	char	*stash;
	int		n_byte;

	n_byte = 1;
	stash = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!stash)
		return (0);
	while (!ft_strchr(*buffer, '\n') && n_byte > 0)
	{
		n_byte = read(fd, stash, BUFFER_SIZE);
		if (n_byte < 0)
		{
			free(stash);
			return (-1);
		}
		if (n_byte == 0)
		{
			free(stash);
			return (0);
		}
		stash[n_byte] = '\0';
		*buffer = ft_strjoin(*buffer, stash);
	}
	free(stash);
	return (n_byte);
}

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_get_lines(char	*buffer)
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
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char ) * (i + 1));
	while (i > l)
	{
		line[l] = buffer[l];
		l++;
	}
	line[l] = '\0';
	return (line);
}

char	*ft_new_buffer_start(char *buffer)
{
	size_t	i;
	size_t	l;
	char	*res;

	l = 0;
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	res = malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (!res)
		return (0);
	while (buffer[i])
	{
		res[l] = buffer[i];
		i++;
		l++;
	}
	res[l] = '\0';
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	error = ft_read_till_sep(fd, &buffer);
	if (!buffer)
		return (NULL);
	if (error == -1)
		return (ft_free(&buffer));
	if (error == 0)
	{
		line = ft_get_lines(buffer);
		ft_free(&buffer);
		if (line[0])
			return (line);
		free(line);
		return (NULL);
	}
	line = ft_get_lines(buffer);
	buffer = ft_new_buffer_start(buffer);
	return (line);
}
