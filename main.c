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
	next_line = get_next_line(fd);
	printf("%s\n", next_line);	
	//close(fd);
	next_line = get_next_line(fd);
	printf("%s", next_line);	
	next_line = get_next_line(fd);
	printf("%s", next_line);
	return (0);
}
