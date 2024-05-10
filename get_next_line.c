/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/10 20:12:24 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void print_newline(char *buffer)
{
	char c;

	while (*buffer && *buffer != '\n')
	{
		if (*buffer == '\n')
		{
			write(1, "\\", 1);
		}
		else
		{
			c = *buffer;
			write(1, &c, 1);
		}
		buffer++;
	}
}

static char *read_file(int fd)
{
	int bytes_read;
	char *buffer;

	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	print_newline(buffer);
	if (bytes_read <= 0)
		return (free(buffer), NULL);
	return (buffer);
}

char *get_next_line(int fd)
{
	char *buff;

	buff = read_file(fd);
	return (buff);
}
