/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:07:23 by asouchet          #+#    #+#             */
/*   Updated: 2022/10/30 15:07:25 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h> 	// size_t
# include <sys/types.h> // ssize_t
# include <stdlib.h> 	// malloc, free
# include <unistd.h> 	// read
# include <stdio.h>

// gnl
char	*get_next_line(int fd);
int		ft_read_till_sep(int fd, char **buffer);

// les fonction appeller dans gnl
char	*ft_get_lines(char	*buffer);
char	*ft_new_buffer_start(char *buffer);

// les utils
char	*ft_strjoin(char *buffer, char *stash);
char	*ft_strchr(char *stash, int c);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif