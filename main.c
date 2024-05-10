#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *next_line;
	int count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			break;
		count++;
		free(next_line);
		next_line = NULL;
	}
	//close(fd);
	return (0);
}
