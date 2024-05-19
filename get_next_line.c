/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:46 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/19 20:05:41 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static int initialize(int fd, char *buffer,  char **nl_p, char **line)
{
	*line = malloc(1);
	if (!line)
		return (0);
	if(fd < 0 || !buffer || !nl_p)
	{
		free(line);
		return (0);
	}
	(*line)[0] = '\0';
	*nl_p = ft_strchr(buffer, '\n');
	return (1);
}

static int read_file(int fd, char *buffer)
{
	ssize_t bytes_read;
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *nl_p = NULL;
	char *line = NULL;
	int read_result;

	if (!initialize(fd, buffer, &nl_p, &line))
		return (NULL);
	
	while (!nl_p)
	{
		read_result = read_file(fd, buffer);
		if (read_result == -1)
		{
			free(line);
			return (NULL);
		}
		else if (read_result > 0)
		{
			nl_p = ft_strchr(buffer, '\n');
			if (nl_p)
				break;
			else
				line = ft_strjoin(line, buffer, BUFFER_SIZE);
			if (!line)
				return (NULL);
		}
		else if (read_result == 0)
			return (line);			
	}
	line = ft_strjoin(line, buffer, nl_p - buffer);
	if (!line)
		return (NULL);
	ft_memmove(buffer, nl_p + 1, ft_strlen(nl_p + 1) + 1);
	return (line);
}
*/

#include "get_next_line.h"

static int initialize(char **line, char **nl_p, char *buffer, int fd)
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

static int read_file(int fd, char *buffer, char **line)
{
    ssize_t bytes_read;

    ft_bzero(buffer, BUFFER_SIZE + 1);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0)
    {
        free(*line);
        return (-1);
    }
    if (bytes_read == 0)
    {
        if (**line == '\0')
        {
            free(*line);
            return (-1);
        }
        return (0);
    }
    return (1);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    char *nl_p;
    int read_result;

    if (!initialize(&line, &nl_p, buffer, fd))
		return (NULL);
    while (nl_p == NULL)
    {
        line = ft_strjoin(line, buffer, ft_strlen(buffer));
        if (!line)
            return (NULL);
        read_result = read_file(fd, buffer, &line);
        if (read_result == -1)
            return (NULL);
        if (read_result == 0)
            return (line);
        nl_p = ft_strchr(buffer, '\n');
    }
    line = ft_strjoin(line, buffer, (nl_p - buffer) + 1);
    if (!line)
        return (NULL);
    ft_memmove(buffer, nl_p + 1, ft_strlen(nl_p + 1) + 1);
    return (line);
}

