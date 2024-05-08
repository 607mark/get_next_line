/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/08 20:09:20 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	int bytes_read;
	char *buffer;

	buffer = malloc (3 + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	if (bytes_read <= 0)
		return (NULL);
	return (buffer);
}
