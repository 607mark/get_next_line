/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/18 20:55:16 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int read_file(int fd, char *buffer, char **line)
{

}

char *get_next_line(int fd)
{
	static char *buffer[BUFFER_SIZE + 1];
}
