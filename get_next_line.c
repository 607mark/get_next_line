/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/10 17:36:09 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static char *read_file(int fd)
{
	int bytes_read;
	char *buffer;

	buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
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
