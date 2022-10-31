/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:30:43 by mtoia             #+#    #+#             */
/*   Updated: 2022/04/29 15:31:13 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*saved[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	if (!saved[fd])
		saved[fd] = ft_strdup("");
	saved[fd] = ft_readnsave(fd, saved[fd]);
	if (!saved[fd])
		return (0);
	line = ft_substr(saved[fd], 0, ft_srch(saved[fd], '\n') + 1, 0);
	saved[fd] = ft_substr(saved[fd], ft_srch(saved[fd], '\n') + 1,
			ft_strlen(saved[fd]), 1);
	return (line);
}
