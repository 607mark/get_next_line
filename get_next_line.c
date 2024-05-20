/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/20 21:29:47 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	initialize(char **line, char **nl_p, char *buffer, int fd)
{
	if (fd < 0)
		return (0);
	*line = malloc(1);
	if (*line == NULL)
		return (0);
	**line = '\0';
	*nl_p = ft_strchr(buffer, '\n');
	return (1);
}

static ssize_t	read_file(int fd, char *buffer, char **line)
{
	ssize_t		bytes_read;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		free(*line);
	if (bytes_read == 0 && **line == '\0')
	{
		free(*line);
		return (-1);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	char			*nl_p;
	ssize_t			bytes_read;

	if (!initialize(&line, &nl_p, buffer, fd))
		return (NULL);
	while (nl_p == NULL)
	{
		line = strjoin_gnl(line, buffer, ft_strlen(buffer));
		if (!line)
			return (NULL);
		bytes_read = read_file(fd, buffer, &line);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			return (line);
		nl_p = ft_strchr(buffer, '\n');
	}
	line = strjoin_gnl(line, buffer, (nl_p - buffer) + 1);
	if (!line)
		return (NULL);
	ft_memmove(buffer, nl_p + 1, ft_strlen(nl_p + 1) + 1);
	return (line);
}
