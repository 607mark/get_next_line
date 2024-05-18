#include "get_next_line.h"

/*
char *get_next_line(int fd)
{

	static char left[BUFFER_SIZE + 1];
	left[BUFFER_SIZE] = '\0';
    char buffer[BUFFER_SIZE + 1];
    char *line = NULL;
    char *nl_p = NULL;
    ssize_t bytes;
	if (fd < 0)
	{
		return (0);
	line = ft_strjoin(line, left);
	ft_bzero(left, BUFFER_SIZE);
    buffer[BUFFER_SIZE] = '\0'; // Ensure null-termination
    while (!(ft_strchr(buffer, '\n')) && nl_p == NULL)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0) // Check for read error
            return NULL;
        if (bytes == 0) // Check for end-of-file
            break;
        buffer[bytes] = '\0'; // Null-terminate the buffer
		nl_p = ft_strchr(buffer, '\n');
		if (nl_p)
			*nl_p = '\0';
		line = ft_strjoin(line, buffer);
		if (!line) // Check for memory allocation failure
           	return NULL;
    }
	ft_memmove(left, nl_p + 1, ft_strlen(nl_p + 1) + 1);
	line = ft_strjoin(line, "\n");
    return line;
}
*/
/*
char *get_next_line(int fd)
{
    static char left[BUFFER_SIZE + 1];
    char buffer[BUFFER_SIZE + 1];
    char *line = NULL;
    char *nl_p = NULL;
    ssize_t bytes;

    if (fd < 0)
	{
        return NULL;
    }

    left[BUFFER_SIZE] = '\0';
    line = ft_strjoin(line, left);
    if (!line) {
        return NULL;
    }
    ft_bzero(left, BUFFER_SIZE);

    while (1) {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0) {
            free(line);
            return NULL;
        }
        if (bytes == 0) {
            break;
        }
        buffer[bytes] = '\0';

        nl_p = ft_strchr(buffer, '\n');
        if (nl_p)
		{
            *nl_p = '\0';
            ft_memmove(left, nl_p + 1, ft_strlen(nl_p + 1) + 1);
        }

        char *new_line = ft_strjoin(line, buffer);
        free(line);
        if (!new_line) {
            return NULL;
        }
        line = new_line;

        if (nl_p) {
            break;
        }
    }

    if (ft_strlen(line) == 0) {
        free(line);
        return NULL;
    }
    return line;
}
*/
char *get_next_line(int fd)
{
    static char left[BUFFER_SIZE + 1];
    char buffer[BUFFER_SIZE + 1];
    char *line = NULL;
    char *nl_p = NULL;
    ssize_t bytes;

    if (fd < 0) {
        return NULL;
    }

    left[BUFFER_SIZE] = '\0';
    line = ft_strjoin(line, left, ft_strlen(left));
    if (!line) {
        return NULL;
    }
    ft_bzero(left, BUFFER_SIZE);

    while (1) {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0) {
            free(line);
            return NULL;
        }
        if (bytes == 0) {
            break;
        }
        buffer[bytes] = '\0';

        nl_p = ft_strchr(buffer, '\n');
        if (nl_p) {
            *nl_p = '\0';
        }

        char *new_line = ft_strjoin(line, buffer, nl_p - buffer + 1);
        free(line);
        ft_memmove(left, nl_p + 1, ft_strlen(nl_p + 1) + 1);
        if (!new_line) {
            return NULL;
        }
        line = new_line;

        if (nl_p) {
            break;
        }
    }

    if (ft_strlen(line) == 0) {
        free(line);
        return NULL;
    }
    return line;
}
