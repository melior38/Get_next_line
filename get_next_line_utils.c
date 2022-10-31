
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
	free 
	return (res);
}
