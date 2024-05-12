/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/12 18:14:32 by mshabano         ###   ########.fr       */
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
	if (!buffer)
		return (0);
	buffer[BUFFER_SIZE] = '\0';
	line = ft_strdup("");
	if (fd < 0)
		return (0);
	while (!nl_p)
	{
		if (*buffer != '\0')
			ft_strjoin(line, buffer);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\n'))
		{
			nl_p = ft_strchr(buffer, '\n');
			*nl_p = '\0';
			ft_strjoin(line, buffer);
			buffer = ft_strdup(nl_p + 1);
			return (line);
		}
	}
	//nl_p = ft_strchr(buffer, '\n');
	return(line);
}
