/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:31:56 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/02 02:31:58 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h> 	// size_t
# include <sys/types.h> // ssize_t
# include <stdlib.h> 	// malloc, free
# include <unistd.h> 	// read
# include <stdio.h>

# ifndef FD_SIZE
#  define FD_SIZE 4096
# endif

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
