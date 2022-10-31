/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:28:00 by mtoia             #+#    #+#             */
/*   Updated: 2022/04/28 13:59:45 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

int	ft_srch(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_readnsave(int fd, char *saved)
{
	int		readbytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(saved, '\n'))
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1 || readbytes == 0)
			break ;
		buffer[readbytes] = '\0';
		saved = ft_strjoin(saved, buffer);
	}			
	free(buffer);
	if (ft_strlen(saved) == 0)
	{
		free(saved);
		return (NULL);
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	if (!saved)
		saved = ft_strdup("");
	saved = ft_readnsave(fd, saved);
	if (!saved)
		return (0);
	line = ft_substr(saved, 0, ft_srch(saved, '\n') + 1, 0);
	saved = ft_substr(saved, ft_srch(saved, '\n') + 1,
			ft_strlen(saved), 1);
	return (line);
}
