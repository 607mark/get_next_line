#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{

		
		int fd = open("test.txt", O_RDONLY);
		if (fd < 0)
		{
			printf("Open failed\n");
			return 1;
		}
		char	*hui;
		while ((hui = get_next_line(fd)) != NULL)
		{
			printf("Next_line = %s", hui);
			free(hui);
		}
		printf("\n");
		close(fd);
	return 0;
}
