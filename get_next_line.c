/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/12 20:12:38 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	char *nl_p;
	ssize_t bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	line = NULL;
	nl_p = NULL;
	if (fd < 0 || !buffer)
		return (0);
	while (nl_p == NULL)
	{
		nl_p = ft_strchr(buffer, '\n');
		if (nl_p)
			*nl_p = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (0);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (0);
		else if (bytes == 0)
		{
			if (*line == '\0')
				return (0);
			else
				return (line);
		}
		nl_p = ft_strchr(buffer, '\n');
		*nl_p = '\0';
	}
	line = ft_strjoin(line, buffer);
	if (!line)
		return (0);
	buffer = ft_strdup(nl_p + 1);
	return(line);
}
