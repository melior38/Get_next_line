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


char	*ft_read_till_sep(int fd, char *buffer)
{
	char	*stach;
	int		n_byte;

	n_byte = 1;
	stach = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!stach)
		return (0);
	while (!ft_strchr(buffer, '\n') && n_byte != 0)
	{
		n_byte = read(fd, stach, BUFFER_SIZE);
		if (n_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, stach);
	}
	free(stach);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;// variable dans laquelle je stocke mon reste de read
	char	*line;// la line concatener se terminant par un \n

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read_till_sep(fd, buffer);// une fonction read et strjoin le line et buffer au fil du read
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);// ft_get_line renvoie la str lu et concatener par read et ft_strjoin mais couper au \n
	buffer = ft_new_bufffer_start(buffer);// cette fonction a pour but de recuperer le reste de la str pris en compte dans ft_get_line
	return (line);
}